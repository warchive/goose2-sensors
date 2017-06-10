import math
import numpy as np
import random
import scipy.signal as signal


# JSON format: {"Name":"Gyro","x":0.45500,"y":2.22250,"z":1.41750}
def parseMonotype(data):
    # data is an array of JSON objects
    # return type: {name: [ [x-array], [y-array], [z-array] ]}
    name = data[0]["Name"]
    x = []
    y = []
    z = []
    for i in range(len(data)):
        x.append(data[i]["x"])
        y.append(data[i]["y"])
        z.append(data[i]["z"])
    retval = {}
    retval[name] = [x, y, z]
    return retval


## subroutine for simulation using a uniform PRNG
def generateMockData(a, b, iters, array):
    count = 0
    while (count < iters):
        array.append(random.uniform(a, b))
        count += 1
    return array


# mockX = []
# mockY = []
# mockZ = []
# mockX = generateMockData(0, 1, 100, mockX)
# mockY = generateMockData(2, 3, 100, mockY)
# mockZ = generateMockData(1, 2, 100, mockZ)

def processMonotype(data, type):
    # data is the return result from parseMonotype
    x = data[type][0]
    y = data[type][1]
    z = data[type][2]
    b, a = signal.butter(8, 0.125)
    xfilt = signal.filtfilt(b, a, x, padlen=math.sqrt(len(x)))
    yfilt = signal.filtfilt(b, a, y, padlen=math.sqrt(len(y)))
    zfilt = signal.filtfilt(b, a, z, padlen=math.sqrt(len(z)))
    np.abs(xfilt - x).max()
    np.abs(yfilt - y).max()
    np.abs(zfilt - z).max()
    retval = {}
    retval[type] = [xfilt, yfilt, zfilt]
    return retval

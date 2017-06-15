# Curve Smoothing with Support Vector Regression using Radial Basis Function (RBF) kernel
# SVR(kernel='rbf', degree=3, gamma='auto', coef0=0.0, tol=0.001, C=1.0, epsilon=0.1, shrinking=True, cache_size=200, verbose=False, max_iter=-1)
import numpy as np
from sklearn.svm import SVR
import timeit

start = timeit.default_timer()


def SVR_process(filename):
    f = open(filename, 'r')
    retArray = f.readlines();
    f.close()
    print("function successfully called")
    print(retArray[0])
    ## process JSON log files here
    X = []
    Y = []
    Z = []
    dataType = ""
    t = []
    svr_rbf = SVR(kernel='rbf', C=1e3, gamma=0.1, verbose=False)
    y_rbf = svr_rbf.fit(t, X).predict(t)
    returnJson = {}
    return returnJson

stop = timeit.default_timer()

print(stop - start)
import abc


class Matrix(object):
    __metaclass__ = abc.ABCMeta

    size = 0

    def __init__(self, size):
        self.size = size

    @abc.abstractmethod
    def get(self, i, j):
        "Returns Matrix value at (i, j)"
        return

    @abc.abstractmethod
    def put(self, i, j, value):
        "sets matrix value at (i, j)"
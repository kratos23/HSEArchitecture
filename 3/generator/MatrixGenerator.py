import abc



class MatrixGenerator(object):
    MAX_ABSOLUTE_MATRIX_VALUE = 1e9

    @abc.abstractmethod
    def generate(self, size):
        "Generates new matrix with given size"
        return

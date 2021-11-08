from matrix import Matrix


class MatrixDiagonal(Matrix):

    def __init__(self, size):
        super().__init__(size)
        self.data = [0.0] * size

    def get(self, i, j):
        self._index_check(i, j)
        if i != j:
            return 0
        else:
            return self.data[i]

    def put(self, i, j, value):
        self._index_check(i, j)
        if i == j:
            self.data[i] = value
        else:
            raise IndexError("Invalid indexes")

    def _index_check(self, i, j):
        if i < 0 or i >= self.size or j < 0 or j >= self.size:
            raise IndexError("Invalid indexes")

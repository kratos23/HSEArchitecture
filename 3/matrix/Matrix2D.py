from matrix import Matrix


class Matrix2D(Matrix):

    def __init__(self, size):
        super().__init__(size)
        self.data = [0] * size
        for i in range(size):
            self.data[i] = [0] * size

    def get(self, i, j):
        return self.data[i][j]

    def put(self, i, j, value):
        self.data[i][j] = value

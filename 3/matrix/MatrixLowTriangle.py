from matrix import Matrix


class MatrixLowTriangle(Matrix):
    def __init__(self, size):
        super().__init__(size)
        self.data = [0] * self._get_array_size()

    def get(self, i, j):
        self._index_check(i, j)
        if j <= i:
            return self.data[self._get_cell_index(i, j)]
        else:
            return 0

    def put(self, i, j, value):
        self._index_check(i, j)
        if j <= j:
            self.data[self._get_cell_index(i, j)] = value
        else:
            raise IndexError("Can't set value above main diagonal")

    def _index_check(self, i, j):
        if i < 0 or i >= self.size or j < 0 or j >= self.size:
            raise IndexError("Invalid indexes")

    def _get_array_size(self):
        return (self.size * (self.size + 1)) // 2

    def _get_cell_index(self, i, j):
        passed = (i * (i + 1)) // 2
        return passed + j

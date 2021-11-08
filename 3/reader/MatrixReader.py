import abc


class MatrixReader(object):

    @abc.abstractmethod
    def read(self, input_stream):
        "Reads matrix from given input stream"
        return


template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t endpoint;
    int min, max;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _array = new T[_size];
        endpoint = 0;
        min = -2147483647;
        max = 2147483647;
    }

    void AppendElem(T elem) {
        min = elem < min ? elem : min;
        max = elem > max ? elem : max;

        if (endpoint ==_size) {
            _size *= 2;
            T* tempArray = new T[_size];

            for (int i = 0; i < endpoint; i++) {
                tempArray[i] = _array[i];
            } 

            delete[] _array;
            _array = tempArray;
            delete[] tempArray;
        }

        _array[endpoint] = elem;
        endpoint++;
    }


    bool IsContains(T elem) {
        for (int i = 0; i < endpoint; i++) {
		    if (elem == _array[i]) return true;
	}
        return false;
    }

    T GetMax() {
        return max;
    }

    T GetMin() {
        return min;
    }

    ~ArrayHandler() {
        delete[] _array;
    }

};


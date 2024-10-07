// exo3.cpp

class Square
{
public:
    Square()
        : mSize(1)
    {
    }

    Square(int size)
        : mSize(size)
    {
    }

    int Perimeter() {
        return mSize * 4;
    }

    int Area() {
        return mSize * mSize;
    }

    int GetSize() { return mSize; }
    void SetSize(int size) { mSize = size; }
private:
    int mSize;
};

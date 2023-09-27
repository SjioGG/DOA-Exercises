template <typename Element> // Key and Value are template parameters

class Array
{
private:
    Element data[]; // vector of pairs for storing the key-value pairs

public:
    Array(int n)
    {
        data = new Element[n];
        for (Element i = 0; i < n; i++)
        {
            data<Element>[i] = i++;
        }
    }
    bool recursive(Element x)
    {
        if (x == 0)
        {
            return false;
        }
        else
        {
            int j = 0;
            while (!data.empty())
            {
                if (recursive(j++) == true)
                    return 1;
            }
        }
    }
};
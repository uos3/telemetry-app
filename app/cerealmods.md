# modifications made to the cereal library

## output c arrays as json arrays, and don't output the null-termination of char[]s.

in `types/common.hpp`:

```cpp
    template <class T, int S>
    int arrayLength (T(&)[S]) { return S; }

    //! Serialization for arrays if BinaryData is not supported or we are not arithmetic
    /*! @internal */
    template <class Archive, class T> inline
    void serializeArray( Archive & ar, T & array, std::false_type /* binary_supported */ )
    {
      size_type s = arrayLength(array);
      // adding a size tag makes cereal treat this as a dynamic array -> outputs a json array.
      ar(make_size_tag(s));

      // if we're dealing with a char[], don't output the null-termination.
      size_type end = s;
      if (s > 0 && typeid(array[0]) == typeid(char))
        end = s-1;

      for (int i=0;i<end;i++)
        ar( array[i] );
    }
```

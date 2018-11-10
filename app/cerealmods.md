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
      ar(make_size_tag(s));

      bool chars = false;
      if (s > 0 && typeid(array[0]) == typeid(char))
        chars = true;

      if (chars) {
        for (int i=0;i<s-1;i++)
          ar( array[i] );
      } else {
        // original function body:
        for( auto & i : array )
          ar( i );
      }
    }
```

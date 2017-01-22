#include <cstdint>

/*!
 * Byte shuffling algorithm applied to size bytes starting at input, with
 * element length itemSize in bytes. Writes the shuffled data to the output
 * array.
 */
void Shuffle( uint8_t* output, const uint8_t* input, size_t size, size_t itemSize )
{
   if ( size > 0 )
      if ( input != nullptr )
         if ( output != nullptr )
         {
            size_t numberOfItems = size / itemSize;
            uint8_t* s = output;
            for ( size_t j = 0; j < itemSize; ++j )
            {
               const uint8_t* u = input + j;
               for ( size_t i = 0; i < numberOfItems; ++i, ++s, u += itemSize )
                  *s = *u;
            }
            ::memcpy( s, input + numberOfItems*itemSize, size % itemSize );
         }
}

/*!
 * Reverse byte shuffling algorithm applied to size bytes starting at input,
 * with element length itemSize in bytes. Writes the unshuffled data to the
 * output array.
 */
void Unshuffle( uint8_t* output, const uint8_t* input, size_t size, size_t itemSize )
{
   if ( size > 0 )
      if ( input != nullptr )
         if ( output != nullptr )
         {
            size_t numberOfItems = size / itemSize;
            const uint8_t* s = input;
            for ( size_t j = 0; j < itemSize; ++j )
            {
               uint8_t* u = output + j;
               for ( size_t i = 0; i < numberOfItems; ++i, ++s, u += itemSize )
                  *u = *s;
            }
            ::memcpy( output + numberOfItems*itemSize, s, size % itemSize );
         }
}

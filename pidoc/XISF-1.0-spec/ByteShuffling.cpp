#include <cstdint>
#include <string.h>

/*!
 * Byte shuffling algorithm.
 *
 * output      The output array, where the shuffled array will be stored. This
 *             array must have capability for at least size bytes.
 *
 * input       The source unshuffled array.
 *
 * size        Length in bytes of the arrays.
 *
 * itemSize    Length of an array item.
 */
void Shuffle( uint8_t* output, const uint8_t* input, size_t size, size_t itemSize )
{
   if ( size > 0 )
      if ( itemSize > 0 )
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
 * Reverse byte shuffling algorithm.
 *
 * output      The output array, where the unshuffled array will be stored.
 *             This array must have capability for at least size bytes.
 *
 * input       The source shuffled array.
 *
 * size        Length in bytes of the arrays.
 *
 * itemSize    Length of an array item.
 */
void Unshuffle( uint8_t* output, const uint8_t* input, size_t size, size_t itemSize )
{
   if ( size > 0 )
      if ( itemSize > 0 )
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

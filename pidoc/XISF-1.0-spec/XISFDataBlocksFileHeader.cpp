#include <cstdint>

/*
 * XISF data blocks file header.
 */
struct XISFDataBlocksFileHeader
{
   uint8_t  signature[ 8 ]; // 'XISB0100'
   uint64_t reserved = 0;   // reserved - must be zero

   /*
    * Constructs a default XISF data blocks file header.
    */
   XISFDataBlocksFileHeader()
   {
      signature[0] = 'X'; signature[1] = 'I'; signature[2] = 'S'; signature[3] = 'B';
      signature[4] = '0'; signature[5] = '1'; signature[6] = '0'; signature[7] = '0';
   }

   /*
    * Returns true if this is a valid XISF data blocks file header.
    */
   bool IsValid() const
   {
      return
      signature[0] == 'X' && signature[1] == 'I' && signature[2] == 'S' && signature[3] == 'B' &&
      signature[4] == '0' && signature[5] == '1' && signature[6] == '0' && signature[7] == '0';
   }
};

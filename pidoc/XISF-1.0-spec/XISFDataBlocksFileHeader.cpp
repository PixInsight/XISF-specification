#include <cstdint>

/*
 * XISF data blocks file header.
 */
struct XISFDataBlocksFileHeader
{
   uint8_t  magic[ 8 ];   // 'XISB0100'
   uint64_t reserved = 0; // reserved - must be zero

   /*
    * Constructs a default XISF data blocks file header.
    */
   XISFDataBlocksFileHeader()
   {
      magic[0] = 'X'; magic[1] = 'I'; magic[2] = 'S'; magic[3] = 'B';
      magic[4] = '0'; magic[5] = '1'; magic[6] = '0'; magic[7] = '0';
   }

   /*
    * Returns true if this is a valid XISF data blocks file header.
    */
   bool IsValid() const
   {
      return magic[0] == 'X' && magic[1] == 'I' && magic[2] == 'S' && magic[3] == 'B' &&
             magic[4] == '0' && magic[5] == '1' && magic[6] == '0' && magic[7] == '0';
   }
};

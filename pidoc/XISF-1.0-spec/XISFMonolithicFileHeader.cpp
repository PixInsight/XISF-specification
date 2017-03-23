#include <cstdint>

/*
 * Monolithic XISF file header.
 */
struct XISFMonolithicFileHeader
{
   uint8_t  signature[ 8 ]; // 'XISF0100'
   uint32_t headerLength;   // length in bytes of the XML file header
   uint32_t reserved = 0;   // reserved - must be zero

   /*
    * Constructs a monolithic XISF file header with the specified XML header
    * length in bytes.
    */
   XISFMonolithicFileHeader( uint32_t _headerLength )
   {
      signature[0] = 'X'; signature[1] = 'I'; signature[2] = 'S'; signature[3] = 'F';
      signature[4] = '0'; signature[5] = '1'; signature[6] = '0'; signature[7] = '0';
      headerLength = _headerLength;
   }

   /*
    * Returns true if this is a valid monolithic XISF file header.
    */
   bool IsValid() const
   {
      return
      signature[0] == 'X' && signature[1] == 'I' && signature[2] == 'S' && signature[3] == 'F' &&
      signature[4] == '0' && signature[5] == '1' && signature[6] == '0' && signature[7] == '0' &&
      headerLength >= 65; // minimum length of an empty header from "<?xml..." to </xisf>
   }
};

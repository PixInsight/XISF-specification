XISF-specification
==================

Extensible Image Serialization Format (XISF) is a free file format for storage, management and interchange of digital images and associated data.

XISF has been originally designed and implemented as the native file format of PixInsight, an image processing software platform designed specifically for astronomical imaging, and developed by the company Pleiades Astrophoto S.L. However, our hope is that XISF serves as an efficient tool for the development of imaging software, including not only software specialized in astronomy, but image processing software in a wide range of technical and general fields.

Two key elements in the design of XISF can be found in its title: *extensible* and *serialization*. Extensibility is crucial to adapt the format easily and efficiently to the requirements of present and future software applications. The architecture of XISF has to facilitate the development of extensions to the core format specification, and for this purpose XISF headers are standard XML documents. Serialization denotes the ability of XISF to store not just image data, but also data structures associated with the environments where the images evolve as living objects. These data structures can be deserialized to recreate the images along with their working contexts. We formalize the resources to store data structures and objects as properties of a variety of predefined data types. XISF properties can be directly associated with images, with entire XISF units, or be defined as standalone components.

Finally, XISF is a free format open to the contributions of anyone interested, including users of PixInsight and other applications, as well as individuals and groups from other development teams, institutions and companies involved or interested in image processing software.

This repository maintains the latest version of XISF format specification in PIDoc source code. The online version of the latest XISF specification document is available here:

http://pixinsight.com/doc/docs/XISF-1.0-spec/XISF-1.0-spec.html

For discussion on the XISF specification, please join us at PixInsight Forum:

http://pixinsight.com/forum/index.php?board=20.0

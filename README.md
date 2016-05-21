# ReversingWin64
Examples used in the series of articles [Ingenieria-inversa-de-aplicaciones-Win64](http://www.sidertia.com/Home/Community/Blog/2016/01/25/Ingenieria-inversa-de-aplicaciones-Win64-I) 
about reversing and exploiting in Windows 64 bits platforms published at www.sidertia.com

## The articles
Introductory course about reversing and exploiting Windows Native applications in modern operating systems covering the following topics:
+ x86_64 arquitecture
+ PE loader and PE32+ format
+ Dynamic analysis with WinDbg
+ Antidebugging techniques
+ Modern anti-exploit protections like Control Flow Guard, Memory Protection and Isolated Heap
+ Vulnerable code and exploitation

## The examples
Each branch in the repository is an example mentioned in the articles with the following naming convention:
```bash
ExampleNumber_Chapter_ExampleName
```
To list all branches in the repository:
```bash
git branch
```
To change to a specific branch:
```bash
git checkout NameOfBranch
```
All the examples have been compiled with MS Visual Studio 2013 Ultimate or MS Visual Studio 2015 Community under Windows 8.1 Update 3. The examples will be updated as soon as new articles are published.

## The author
David Fernandez with the help of Sidertia Security Team

## License
(The MIT License)

Copyright (c) 2016 David Fernández Madrid <dfernandez@sidertia.com>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

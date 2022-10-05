from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension
 
sourcefiles = ['Simple.pyx', 'main.c']
 
extensions = [Extension("Simple", sourcefiles,
  include_dirs=[
  'C:\\Program Files\\Java\\jdk1.8.0_291\\include',
  'C:\\Program Files\\Java\\jdk1.8.0_291\\include\\win32',
  'C:\\Users\\Administrator\\AppData\\Local\\Programs\\Python\\Python310',
  'C:\\Users\\Administrator\\AppData\\Local\\Programs\\Python\\Python310\\include'
   ],
  library_dirs=['/usr/lib64'],
  libraries=['python310'])]
 
setup(ext_modules=cythonize(extensions, language_level = 3))
project('tutorial', 'c')
cc = meson.get_compiler('c')
libm = cc.find_library('m', required:true)


sublib = library('mylib', ['./lib/lib.c'], 
	install: false,
	include_directories: ['./lib'])

incdir = include_directories('./lib/')

executable('demo', 'main.c', include_directories: incdir, link_with: sublib)

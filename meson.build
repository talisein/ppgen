
project('ppgen', ['cpp'],
	    version: '1.3.0',
	    license: 'GPL3+',
        default_options : ['cpp_std=c++14',
			               'buildtype=release'])

if not meson.get_compiler('cpp').has_header_symbol('experimental/iterator', '__cpp_lib_experimental_ostream_joiner')
  error('C++ ostream_joiner not available. Use release 1.1')
endif


if not meson.get_compiler('cpp').has_header('pcg_random.hpp')
  pcg_cpp_dep = dependency('pcg-cpp', fallback: ['pcg-cpp'], method: 'cmake')
else
  pcg_cpp_dep = dependency('', required: false)
endif

ppgen = executable('ppgen', 'src/ppgen.cpp',
		           dependencies: pcg_cpp_dep,
		           install: true)

pingen = executable('pingen', 'src/pingen.cpp',
		            dependencies: pcg_cpp_dep,
		            install: true)

install_man('man/ppgen.1')
install_man('man/pingen.1')

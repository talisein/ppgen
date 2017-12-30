project('ppgen', ['cpp'],
	version: '1.1',
	license: 'GPL3+',
        default_options : ['cpp_std=c++14',
			   'buildtype=release'])

pcg_cpp_sp = subproject('pcg-cpp')
pcg_cpp_dep = pcg_cpp_sp.get_variable('pcg_cpp_dep')

ppgen = executable('ppgen', join_paths('src', 'ppgen.cpp'),
		   dependencies: pcg_cpp_dep,
		   install: true)

pingen = executable('pingen', join_paths('src', 'pingen.cpp'),
		   dependencies: pcg_cpp_dep,
		   install: true)

install_man(join_paths('man', 'ppgen.1'))
install_man(join_paths('man', 'pingen.1'))

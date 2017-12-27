project('ppgen', ['cpp'],
	version: '1.1',
	license: 'GPL3+',
        default_options : ['cpp_std=c++14',
			   'build_type=release'])

pcg_cpp_sp = subproject('pcg-cpp')
pcg_cpp_dep = pcg_cpp_sp.get_variable('pcg_cpp_dep')

ppgen = executable('ppgen', 'src/ppgen.cpp',
		   dependencies: pcg_cpp_dep,
		   install: true)

install_man('man/ppgen.1')


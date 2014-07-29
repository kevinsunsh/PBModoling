import glob



env = Environment(CCFLAGS='-O0 -g')   # Create an environmnet

lib_target  = "base"
lib_sources = glob.glob("Base/*.cpp")


lib_base = env.StaticLibrary(target = lib_target,
							source = lib_sources,
							LINKFLAGS="-fPIC")
lecture1 = env.Program(source = ["Lecture1/lecture1.cpp"], 
				target = "lecture1", 
				LIBS=['base', 'glut', 'GL'],
				LIBPATH='.',
				CPPPATH='.')
				
lecture2_sources = glob.glob("Lecture2/*.cpp")	
lecture2 = env.Program(source = lecture2_sources, 
				target = "lecture2", 
				LIBS=['base', 'glut', 'GL'],
				LIBPATH='.',
				CPPPATH='.')




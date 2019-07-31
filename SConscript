from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.
src     = Glob('src/*.c')

if GetDepend('PROTOBUF_C_USING_ENCODE_DECODE_EXAMPLE'):
	src    += Glob('examples/amessage.pb-c.c')
	src    += Glob('examples/amessage_encode_decode.c')

if GetDepend('PROTOBUF_C_USING_ENCODE_DECODE_FILE_EXAMPLE'):
	src    += Glob('examples/amessage.pb-c.c')
	src    += Glob('examples/amessage_encode_to_file.c')
	src    += Glob('examples/amessage_decode_from_file.c')


path   =  [cwd + '/src']
path   += [cwd + '/examples']

LOCAL_CCFLAGS = ''

group = DefineGroup('libann', src, depend = ['PKG_USING_PROTOBUF_C'], CPPPATH = path, LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')

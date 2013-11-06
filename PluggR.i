%module PluggR

%inline %{
    extern const char *pluggr_get_error(int code);
    extern int         pluggr_recognize(const char *face_file,
					const char *recognizer_path);
%}

cc -Wall -Werror -Wextra src/**.c src_tool/**.c src_running/**.c src_terminal/**.c src_cmd/**.c src_error/**.c src_transrate/**.c src_exe/**.c src_global/**.c src_export_tool/**.c src_env_tool/**.c src_file/**.c src_dir/**.c src_builtin/**.c  -I include/  -I include/builtin/ -lreadline 

as >test.txt <text.txt

as>test.txt | echo a < test.txt > text.txt
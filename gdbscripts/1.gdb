define pstrtab
	set $i = 0
	while $arg0[$i] != (void*)0
		print $_as_string($arg0[$i])
		set $i = $i + 1
	end
end
b main
run
n
pstrtab envp

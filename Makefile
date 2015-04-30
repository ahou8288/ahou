all: snapshot.c
	clang snapshot.c
	./a.out

git: snapshot.c
	git add snapshot.c
	git commit -m '$(COM)'
	git push origin master

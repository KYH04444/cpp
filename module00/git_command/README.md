# Git command

## 일반적인 git push 순서

> git add . \
git commit -m "msg" \
git push

    git add .

현재까지 작업중인 파일들을 깃허브에 올리기 위한 Staging area에 올림

    git status

주기적으로 현재 파일의 상태 체크
> Changes not staged for commit: \
  (use "git add <file>..." to update what will be committed) \
  (use "git restore <file>..." to discard changes in working directory) \
	modified:   README.md \
no changes added to commit (use "git add" and/or "git commit -a")


아무것도 안하고 git status 치면 위 같은 메세지 뜸 \
만약 수정하고 git add . 하면 staging area에 올린 파일 확인 가능

    git add .

>On branch master \
Your branch is up to date with 'origin/master'. \
Changes to be committed: \
  (use "git restore --staged <file>..." to unstage) \
	modified:   README.md \
	renamed:    src/test.cpp -> src/cpp.cpp \

'changes to be committed'는 가리키는 파일들이 staged 상태임을 표시

    git commit -m "commit msg"

stage에 올린 애들은 위 명령어로 commit하면 깃허브에 바로 올라갈 준비 끝남 \
나중에 msg를 확인해서 이전 버전으로 되돌아 갈 때 중요한 역할을 하므로 MSG 잘 적자

    git push origin master

origit은 처음 git 설정할 때 현재 remote repository에 붙여준 이름




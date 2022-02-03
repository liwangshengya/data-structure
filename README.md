

数据结构作业代码







git   error: failed to push some refs to 'https://github.com/liwangshengya/picture.git/'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.



解决办法：出现错误的原因是github中的README.md文件不在本地代码目录中。

### 也就是说我们需要先将远程代码库中的任何文件先pull到本地代码库中，才能push新的代码到github代码库中。

### 使用如下命令：git pull --rebase origin master

#### 然后再进行上传: git push -u origin master

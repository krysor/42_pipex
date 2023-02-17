/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:44:12 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/18 10:50:16 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc < 5)
		return (1);
	
	if (!ft_strncmp(argv[1], "here_doc", 8))//DONT FORGET TO MAKE A FLAG CONDITION IN LAST SAVE/EXEC
	{
		if (argc < 6)
			exit(1);//need some exit function here
		
		int		l = ft_strlen(argv[2]);
		
		int	fd = open("temp", O_WRONLY | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
			perror("first file open");

		char	*str = get_next_line(0);
		while (ft_strncmp(str, argv[2], l) || l != (int)ft_strlen(str) - 1)
		{
			write(fd, str, ft_strlen(str));
			free(str);
			str = get_next_line(0);
		}
		close(fd);
		data.i = 3;
		data.fd = open("temp", O_RDONLY);
		if (data.fd == -1)
			perror("first file open");
		dup2(data.fd, STDIN_FILENO);
		close(data.fd);
		unlink("temp");
	}
	else
	{
		data.i = 2;
		data.fd = open(argv[1], O_RDONLY);
		if (data.fd == -1)
			perror("first file open");
		dup2(data.fd, STDIN_FILENO);
		close(data.fd);
	}
	data.paths = ft_getallpaths(envp);
	while (data.i < argc - 1)
	{
		data.args = ft_split(argv[data.i], ' ');
		data.path = ft_getpath(ft_strdup(data.args[0]), data.paths);
		pipe(data.pip);
		data.pid = fork();
		if (!(data.pid))
		{
			if (data.i == argc - 2)
			{
				int	flag = O_WRONLY | O_CREAT | O_CLOEXEC;
				if (ft_strncmp(argv[1], "here_doc", 8))
					flag = flag | O_TRUNC;
				else
					flag = flag | O_APPEND;
				data.fd = open(argv[argc - 1], flag,
								S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				dup2(data.fd, STDOUT_FILENO);
				close(data.fd);
			}
			else
				dup2(data.pip[1], STDOUT_FILENO);
			if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
				perror("execve");
		}
		close(data.pip[1]);
		waitpid(data.pid, NULL, 0);
		dup2(data.pip[0], STDIN_FILENO);
		data.i++;
	}
	//system("leaks pipex");
	//system("lsof -c pipex");
	return (0);
}
/*
int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc < 5)
		return (1);
	data.paths = ft_getallpaths(envp);
	data.i = 2;
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		perror("first file open");
	dup2(data.fd, STDIN_FILENO);
	close(data.fd);
	while (data.i < argc - 2)
	{
		data.args = ft_split(argv[data.i], ' ');
		data.path = ft_getpath(ft_strdup(data.args[0]), data.paths);
		pipe(data.pip);
		data.pid = fork();
		if (!(data.pid))
		{
			dup2(data.pip[1], STDOUT_FILENO);
			if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
				perror("execve");
		}
		close(data.pip[1]);
		waitpid(data.pid, NULL, 0);
		dup2(data.pip[0], STDIN_FILENO);
		data.i++;
	}
	data.pid = fork();
	if (!data.pid)
	{
		data.args = ft_split(argv[data.i], ' ');
		data.path = ft_getpath(ft_strdup(data.args[0]), data.paths);
		data.fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT | O_CLOEXEC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		dup2(data.fd, STDOUT_FILENO);
		close(data.fd);
		if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
			perror("execve");
	}
	waitpid(data.pid, NULL, 0);
	//system("leaks pipex");
	//system("lsof -c pipex");
	return (0);
}*/

/*
int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc < 5)
		return (1);
	data.paths = ft_getallpaths(envp);
	data.i = 2;

	pipe(data.pip[0]);
	pipe(data.pip[1]);
	while (data.i < argc - 1)
	{
		data.args = ft_split(argv[data.i], ' ');
		data.path = ft_getpath(ft_strdup(data.args[0]), data.paths);
	
		data.pid = fork();
		if (!data.pid)
		{
			printf("start fork\n");
			printf("pip[0][0]:%d\npip[0][1]:%d\n", data.pip[0][0], data.pip[0][1]);
			printf("pip[1][0]:%d\npip[1][1]:%d\n", data.pip[1][0], data.pip[1][1]);
			if (data.i == 2)
			{
				close(data.pip[data.i % 2][0]);
				data.fd = open(argv[1], O_RDONLY);
				if (data.fd == -1)
					perror("first file open");
				dup2(data.fd, STDIN_FILENO);
				dup2(data.pip[data.i % 2][1], STDOUT_FILENO);
				close(data.fd);
				close(data.pip[data.i % 2][1]);
				if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
					perror("execve");
			}
			else if (data.i == argc - 2)
			{
				if (data.i % 2)
					(data.i)++;
				close(data.pip[data.i % 2][1]);
				data.fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT | O_CLOEXEC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				if (data.fd == -1)
					perror("second file open");
				dup2(data.pip[data.i % 2][0], STDIN_FILENO);
				dup2(data.fd, STDOUT_FILENO);
				close(data.pip[data.i % 2][0]);
				close(data.fd);
				if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
					perror("execve");
			}
			//NOT SURE IF THIS CORRECT
			close(data.pip[data.i % 2][0]);//write to this
			close(data.pip[!(data.i % 2 && 1)][1]);//read from this
			dup2(data.pip[!(data.i % 2 && 1)][0], STDIN_FILENO);
			dup2(data.pip[data.i % 2][1], STDOUT_FILENO);
			close(data.pip[!(data.i % 2 && 1)][0]);
			close(data.pip[data.i % 2][1]);
			if (execve(data.path, data.args, envp) == -1)//make sure execve proceeds if path is NULL
				perror("execve");
		}
		free(data.args);
		free(data.path);
		close(data.pip[data.i % 2][1]);
		close(data.pip[!(data.i % 2 && 1)][1]);
		waitpid(data.pid, NULL, 0);
		(data.i)++;
	}
	//waitpid(pid, NULL, 0);//WCONTINUED| WNOHANG | WUNTRACED);
	//system("leaks pipex");
	//system("lsof -c pipex");
	return (0);
}*/

//this works for 2 cmds
/*
int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	char	**args = NULL;
	char	*path = NULL;

	if (argc < 5)
		return (1);
		
	//open this in the first
	int	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		perror("first file open");
	//open this in the last
	int	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT | O_CLOEXEC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd2 == -1)
		perror("second file open");
	//this during initialization
	char **paths = ft_getallpaths(envp);
	
	pipe(fd);
	pid_t	pid = fork();
	if (!pid)
	{
		args = ft_split(argv[2], ' ');
		path = ft_getpath(ft_strdup(args[0]), paths);	
		close(fd[0]);
		dup2(fd1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd1);
		close(fd[1]);
		if (execve(path, args, envp) == -1)//make sure execve proceeds if path is NULL
			perror("execve");
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	pid_t	pid2 = fork();
	if (!pid2)
	{
		//waitpid(pid2, NULL, 0);
		args = ft_split(argv[3], ' ');
		path = ft_getpath(ft_strdup(args[0]), paths);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		close(fd[0]);
		close(fd2);
		if (execve(path, args, envp) == -1)//make sure execve proceeds if path is NULL
			perror("execve");
	}
	printf("pid before wait: %d\n", (int)pid);
	close(fd[1]);
	waitpid(pid, NULL, 0);//WCONTINUED| WNOHANG | WUNTRACED);
	printf("pid after wait: %d\n", (int)pid);
	//system("leaks pipex");
	//system("lsof -c pipex");
	return (0);
}
*/

/*
int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	char	**args = NULL;
	char	*path = NULL;

	if (argc != 5)
		return (1);

	int	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		perror("first file open");

	int	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT | O_CLOEXEC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd2 == -1)
		perror("second file open");
	
	char **paths = ft_getallpaths(envp);
	
	pipe(fd);
	pid_t	pid = fork();
	if (!pid)
	{
		pid_t	pid2 = fork();
		printf("pid2 after second fork: %d\n", (int)pid2);
		if (!pid2)
		{
			args = ft_split(argv[2], ' ');
			path = ft_getpath(ft_strdup(args[0]), paths);	
			close(fd[0]);
			dup2(fd1, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd1);
			close(fd[1]);
			if (execve(path, args, envp) == -1)//make sure execve proceeds if path is NULL
				perror("execve");
		}
		else
		{
			close(fd[1]);
			waitpid(pid2, NULL, 0);
			//close(fd[1]);
			args = ft_split(argv[3], ' ');
			path = ft_getpath(ft_strdup(args[0]), paths);
			dup2(fd[0], STDIN_FILENO);
			dup2(fd2, STDOUT_FILENO);
			close(fd[0]);
			close(fd2);
			if (execve(path, args, envp) == -1)//make sure execve proceeds if path is NULL
				perror("execve");
		}	
	}
	else if (pid == -1)
	{
		perror(NULL);
		return (1);
	}
	else
	{
		close(fd[1]);
		//close(fd2);
		printf("pid before wait: %d\n", (int)pid);
		waitpid(pid, NULL, 0);//WCONTINUED| WNOHANG | WUNTRACED);
		printf("pid after wait: %d\n", (int)pid);
		//system("leaks pipex");
		//system("lsof -c pipex");
	}
	return (0);
}
*/

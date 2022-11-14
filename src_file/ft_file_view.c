/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:10:05 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/26 14:38:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/stat.h>

//stat, lstat, fstat, unlink,

// #define __DARWIN_STRUCT_STAT64 { \
// 	dev_t		st_dev;                 /* [XSI] ID of device containing file */ \
// 	mode_t		st_mode;                /* [XSI] Mode of file (see below) */ \
// 	nlink_t		st_nlink;               /* [XSI] Number of hard links */ \
// 	__darwin_ino64_t st_ino;                /* [XSI] File serial number */ \
// 	uid_t		st_uid;                 /* [XSI] User ID of the file */ \
// 	gid_t		st_gid;                 /* [XSI] Group ID of the file */ \
// 	dev_t		st_rdev;                /* [XSI] Device ID */ \
// 	__DARWIN_STRUCT_STAT64_TIMES \
// 	off_t		st_size;                /* [XSI] file size, in bytes */ \
// 	blkcnt_t	st_blocks;              /* [XSI] blocks allocated for file */ \
// 	blksize_t	st_blksize;             /* [XSI] optimal blocksize for I/O */ \
// 	__uint32_t	st_flags;               /* user defined flags for file */ \
// 	__uint32_t	st_gen;                 /* file generation number */ \
// 	__int32_t	st_lspare;              /* RESERVED: DO NOT USE! */ \
// 	__int64_t	st_qspare[2];           /* RESERVED: DO NOT USE! */ \
// }

// #define __DARWIN_STRUCT_STAT64_TIMES \
// 	struct timespec st_atimespec;           /* time of last access */ \
// 	struct timespec st_mtimespec;           /* time of last data modification */ \
// 	struct timespec st_ctimespec;           /* time of last status change */ \
// 	struct timespec st_birthtimespec;       /* time of file creation(birth) */

#include <stdio.h>
void ft_file_view(char *name)
{
	struct stat file_stat[1];
	
	if (stat(name, file_stat))
	{
		printf("no file\n");
		return ;
	}
	printf("file_stat->st_dev : %d\n", file_stat->st_dev);
	printf("file_stat->st_mode : %d\n", file_stat->st_mode);
	printf("file_stat->st_nlink : %d\n", file_stat->st_nlink);
	printf("file_stat->st_ino : %lld\n", file_stat->st_ino);
	printf("file_stat->st_uid : %d\n", file_stat->st_uid);
	printf("file_stat->st_gid : %d\n", file_stat->st_gid);
	printf("file_stat->st_rdev : %d\n", file_stat->st_rdev);
	printf("__DARWIN_STRUCT_STAT64_TIMES\n");
	printf("	file_stat->st_atimespec : %ld\n", file_stat->st_atimespec.tv_sec);
	printf("	file_stat->st_mtimespec : %ld\n", file_stat->st_mtimespec.tv_sec);
	printf("	file_stat->st_ctimespec : %ld\n", file_stat->st_ctimespec.tv_sec);
	printf("	file_stat->st_birthtimespec : %ld\n", file_stat->st_birthtimespec.tv_sec);
	printf("file_stat->st_size : %lld\n", file_stat->st_size);
	printf("file_stat->st_blocks : %lld\n", file_stat->st_blocks);
	printf("file_stat->st_blksize : %d\n", file_stat->st_blksize);
	printf("file_stat->st_flags : %d\n", file_stat->st_flags);
	printf("file_stat->st_gen : %d\n", file_stat->st_gen);
	printf("file_stat->st_lspare : %d\n", file_stat->st_lspare);
	printf("file_stat->st_qspare[0] : %lld\n", file_stat->st_qspare[0]);
	printf("file_stat->st_qspare[1] : %lld\n", file_stat->st_qspare[1]);
	printf("end file view\n\n");
}
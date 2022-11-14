/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:01:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/26 16:07:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

// DIR *          opendir(const char *name);
// struct dirent *readdir(DIR *dir);
// int            closedir(DIR *dir);

// #define __DARWIN_STRUCT_DIRENTRY { \
// 	__uint64_t  d_ino;      /* file number of entry */ \
// 	__uint64_t  d_seekoff;  /* seek offset (optional, used by servers) */ \
// 	__uint16_t  d_reclen;   /* length of this record */ \
// 	__uint16_t  d_namlen;   /* length of string in d_name */ \
// 	__uint8_t   d_type;     /* file type, see below */ \
// 	char      d_name[__DARWIN_MAXPATHLEN]; /* entry name (up to MAXPATHLEN bytes) */ \
// }
// typedef struct {
// 	int	__dd_fd;	/* file descriptor associated with directory */
// 	long	__dd_loc;	/* offset in current buffer */
// 	long	__dd_size;	/* amount of data returned */
// 	char	*__dd_buf;	/* data buffer */
// 	int	__dd_len;	/* size of data buffer */
// 	long	__dd_seek;	/* magic cookie returned */
// 	__unused long	__padding; /* (__dd_rewind space left for bincompat) */
// 	int	__dd_flags;	/* flags for readdir */
// 	__darwin_pthread_mutex_t __dd_lock; /* for thread locking */
// struct _telldir *__dd_td; /* telldir position recording */
// } DIR;

#include <stdio.h>
#define TYPE_DT(X) \
(\
	(X) == DT_UNKNOWN	?	"unknown file type" :\
	(X) == DT_FIFO		?	"named pipe" :\
	(X) == DT_CHR		?	"character device" :\
	(X) == DT_DIR		?	"directory" :\
	(X) == DT_BLK		?	"block device" :\
	(X) == DT_REG		?	"regular file" :\
	(X) == DT_LNK		?	"symbolic link" :\
	(X) == DT_SOCK		?	"UNIX domain socket" :\
	(X) == DT_WHT		?	"dummy ``whiteout inode''" :\
	"NO"\
)

void ft_dir_view(char *name)
{
	DIR *dir;
	struct dirent *file;
	
	dir = opendir(name);
	if (!dir)
	{
		printf("no dir\n");
		return ;
	}
	printf("dir->__dd_fd : %d\n", dir->__dd_fd);
	printf("dir->__dd_loc : %ld\n", dir->__dd_loc);
	printf("dir->__dd_size : %ld\n", dir->__dd_size);
	printf("dir->__dd_buf : %s\n", dir->__dd_buf);
	printf("dir->__dd_len : %d\n", dir->__dd_len);
	printf("dir->__dd_seek : %ld\n", dir->__dd_seek);
	printf("dir->__padding : %lu\n", dir->__padding);
	printf("dir->__dd_flags : %d\n", dir->__dd_flags);
	//printf("dir->__dd_lock : %ld\n", dir->__dd_lock);
	printf("dir->__dd_td : %p\n", dir->__dd_td);
    while((file = readdir(dir)) != NULL) 
    {
		printf("file->d_ino : %llu\n", file->d_ino);
		printf("file->d_seekoff : %llu\n", file->d_seekoff);
		printf("file->d_reclen : %d\n", file->d_reclen);
		printf("file->d_namlen : %d\n", file->d_namlen);
		printf("file->d_type : %d\n", file->d_type);
		printf("file->d_name : %s\n", file->d_name);
		printf("file->TYPE_DT : %s\n", TYPE_DT(file->d_type));
		printf("end dir view\n\n");
    }
	closedir(dir);


}
/*-
 * Copyright (c) 2009 Gleb Kurtsou <gk@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/queue.h>

#define PEFS_KEYCHAIN_DBFILE		".pefs"

#define PEFS_KEYCHAIN_USE		0x0001
#define PEFS_KEYCHAIN_IGNORE_MISSING	0x0002

struct pefs_keychain
{
	TAILQ_ENTRY(pefs_keychain) kc_entry;
	struct pefs_xkey kc_key;
};

TAILQ_HEAD(pefs_keychain_head, pefs_keychain);

int	pefs_keychain_get(struct pefs_keychain_head *kch,
	    const char *filesystem, int flags, struct pefs_xkey *xk);
int	pefs_keychain_set(const char *filesystem, struct pefs_xkey *xk,
	    struct pefs_xkey *xknext);
int	pefs_keychain_del(const char *filesystem, int flags,
		struct pefs_xkey *xk);
void	pefs_keychain_free(struct pefs_keychain_head *kch);
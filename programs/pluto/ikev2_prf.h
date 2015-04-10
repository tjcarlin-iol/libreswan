/*
 * Calculate IKEv2 prf and keying material, for libreswan
 *
 * Copyright (C) 2007 Michael C. Richardson <mcr@xelerance.com>
 * Copyright (C) 2010 Paul Wouters <paul@xelerance.com>
 * Copyright (C) 2013 D. Hugh Redelmeier <hugh@mimosa.com>
 * Copyright (C) 2015 Andrew Cagney <cagney@gnu.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef _IKEV2_PRF_H
#define _IKEV2_PRF_H

struct v2prf_stuff {
	chunk_t t;
	const struct hash_desc *prf_hasher;
	PK11SymKey *skeyseed;
	chunk_t ni;
	chunk_t nr;
	chunk_t spii;
	chunk_t spir;
	u_char counter[1]; /* why is this an array of 1? */
	unsigned int availbytes;
	unsigned int nextbytes;
};

extern void v2genbytes(chunk_t *need,
		       unsigned int needed, const char *name,
		       struct v2prf_stuff *vps);

struct pluto_crypto_req;

void calc_dh_v2(struct pluto_crypto_req *r);

#endif

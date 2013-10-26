// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _NULLPO_H_
#define _NULLPO_H_

#include "cbasetypes.h"

#define NLP_MARK __FILE__, __LINE__, __func__

// enabled by default on debug builds
#if defined(DEBUG) && !defined(NULLPO_CHECK)
	#define NULLPO_CHECK
#endif

/*----------------------------------------------------------------------------
 * Macros
 *----------------------------------------------------------------------------
 */
/*======================================
 * Null�`�F�b�N �y�� ���o�͌� return
 *�E�W�J�����if�Ƃ�return�����o��̂�
 *  ��s�P�̂Ŏg���Ă��������B
 *�Enullpo_ret(x = func());
 *  �̂悤�Ȏg�p�@���z�肵�Ă��܂��B
 *--------------------------------------
 * nullpo_ret(t)
 *   �߂�l 0�Œ�
 * [����]
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 * nullpo_retv(t)
 *   �߂�l �Ȃ�
 * [����]
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 * nullpo_retr(ret, t)
 *   �߂�l �w��
 * [����]
 *  ret     return(ret);
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 */

#if defined(NULLPO_CHECK)

#define nullpo_ret(t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {return(0);}

#define nullpo_retv(t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {return;}

#define nullpo_retr(ret, t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {return(ret);}

#define nullpo_retb(t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {break;}

#else /* NULLPO_CHECK */
/* No Nullpo check */

// if((t)){;}
// �ǂ����@���v�����Ȃ������̂ŁE�E�E����̍�ł��B
// �ꉞ���[�j���O�͏o�Ȃ��͂�

#define nullpo_ret(t) (void)(t)
#define nullpo_retv(t) (void)(t)
#define nullpo_retr(ret, t) (void)(t)
#define nullpo_retb(t) (void)(t)

#endif /* NULLPO_CHECK */

/*----------------------------------------------------------------------------
 * Functions
 *----------------------------------------------------------------------------
 */
/*======================================
 * nullpo_chk
 *   Null�`�F�b�N �y�� ���o��
 * [����]
 *  file    __FILE__
 *  line    __LINE__
 *  func    __func__ (�֐���)
 *    �����ɂ� NLP_MARK ���g���Ƃ悢
 *  target  �`�F�b�N�Ώ�
 * [�Ԃ�l]
 *  0 OK
 *  1 NULL
 *--------------------------------------
 */
int nullpo_chk(const char *file, int line, const char *func, const void *target);

#endif /* _NULLPO_H_ */

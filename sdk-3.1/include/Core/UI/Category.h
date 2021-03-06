/***********************************************************************
 *
 * Copyright (c) 1994-1999 3Com Corporation or its subsidiaries.
 * All rights reserved.
 *
 * PROJECT:  Pilot
 * FILE:     Category.h
 * AUTHOR:	 Art Lamb: March 7, 1995
 *
 * DECLARER: UI
 *
 * DESCRIPTION:
 *	  This file defines category structures and routines.
 *
 ***********************************************************************/
#ifndef __CATEGORY_H__
#define __CATEGORY_H__


typedef struct {
   Word	renamedCategories;
	Char	categoryLabels [dmRecNumCategories] [dmCategoryLength];
	Byte	categoryUniqIDs[dmRecNumCategories];
	Byte	lastUniqID;	// Uniq IDs generated by the device are between
							// 0 - 127.  Those from the PC are 128 - 255.
} AppInfoType;

typedef AppInfoType * AppInfoPtr;


#ifdef __cplusplus
extern "C" {
#endif

extern void CategoryCreateListV10 (const DmOpenRef db, const ListPtr lst, 
	const Word currentCategory, const Boolean showAll)
							SYS_TRAP(sysTrapCategoryCreateListV10);

extern void CategoryCreateList (const DmOpenRef db, const ListPtr listP, 
	const Word currentCategory, const Boolean showAll, 
	const Boolean showUneditables, const Byte numUneditableCategories, 
	const DWord editingStrID, const Boolean resizeList)
							SYS_TRAP(sysTrapCategoryCreateList);


extern void CategoryFreeListV10 (const DmOpenRef db, const ListPtr lst)
							SYS_TRAP(sysTrapCategoryFreeListV10);

extern void CategoryFreeList (const DmOpenRef db, const ListPtr listP, 
	const Boolean showAll, const DWord editingStrID)
							SYS_TRAP(sysTrapCategoryFreeList);

extern Word CategoryFind (const DmOpenRef db, const Char * const name)
							SYS_TRAP(sysTrapCategoryFind);

extern void CategoryGetName (const DmOpenRef db, const Word index, Char * const name)
							SYS_TRAP(sysTrapCategoryGetName);

extern Boolean CategoryEditV10 (const DmOpenRef db, const WordPtr category)
							SYS_TRAP(sysTrapCategoryEditV10);

extern Boolean CategoryEditV20 (const DmOpenRef db, const WordPtr category, 
	const DWord titleStrID)
							SYS_TRAP(sysTrapCategoryEditV20);

extern Boolean CategoryEdit (const DmOpenRef db, const WordPtr category, 
	const DWord titleStrID, const Byte numUneditableCategories)
							SYS_TRAP(sysTrapCategoryEdit);

extern Boolean CategorySelectV10 (const DmOpenRef db, const FormPtr frm, 
	const Word ctlID, const Word lstID,	const Boolean title, const WordPtr categoryP, 
	CharPtr categoryName)
							SYS_TRAP(sysTrapCategorySelectV10);

extern Boolean CategorySelect (const DmOpenRef db, const FormPtr frm, 
	const Word ctlID, const Word lstID,	const Boolean title, const WordPtr categoryP, 
	CharPtr categoryName, const Byte numUneditableCategories, DWord editingStrID)
							SYS_TRAP(sysTrapCategorySelect);

extern Word CategoryGetNext (const DmOpenRef db, Word index)
							SYS_TRAP(sysTrapCategoryGetNext);

extern void CategorySetTriggerLabel (const ControlPtr ctl, CharPtr name)
							SYS_TRAP(sysTrapCategorySetTriggerLabel);

extern void CategoryTruncateName (CharPtr name, const Word maxWidth)
							SYS_TRAP(sysTrapCategoryTruncateName);

extern void CategoryInitialize (AppInfoPtr appInfoP, const Word localizedAppInfoStrID)
							SYS_TRAP(sysTrapCategoryInitialize);


extern void CategorySetName (const DmOpenRef db, Word index, const CharPtr nameP)
							SYS_TRAP(sysTrapCategorySetName);

#ifdef __cplusplus 
}
#endif

#endif // __CATEGORY_H__

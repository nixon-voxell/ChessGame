// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPieceBundle.h"

FChessPieceBundle::FChessPieceBundle()
{
}

FChessPieceBundle::~FChessPieceBundle()
{
}

void FChessPieceBundle::Initialize()
{
	this->Pieces[0] = NULL;
	this->Pieces[1] = this->Pawn.Item.GetDefaultObject();
	this->Pieces[2] = this->Rook.Item.GetDefaultObject();
	this->Pieces[3] = this->Knight.Item.GetDefaultObject();
	this->Pieces[4] = this->BishopPiece.Item.GetDefaultObject();
	this->Pieces[5] = this->QueenPiece.Item.GetDefaultObject();
	this->Pieces[6] = this->KingPiece.Item.GetDefaultObject();
}

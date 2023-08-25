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
	this->Pieces[1] = this->Pawn.GetDefaultObject();
	this->Pieces[2] = this->Rook.GetDefaultObject();
	this->Pieces[3] = this->Knight.GetDefaultObject();
	this->Pieces[4] = this->BishopPiece.GetDefaultObject();
	this->Pieces[5] = this->QueenPiece.GetDefaultObject();
	this->Pieces[6] = this->KingPiece.GetDefaultObject();
}

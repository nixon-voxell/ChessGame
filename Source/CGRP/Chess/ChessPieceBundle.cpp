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
	this->Pieces[1] = this->Pawn;
	this->Pieces[2] = this->Rook;
	this->Pieces[3] = this->Knight;
	this->Pieces[4] = this->BishopPiece;
	this->Pieces[5] = this->QueenPiece;
	this->Pieces[6] = this->KingPiece;
}

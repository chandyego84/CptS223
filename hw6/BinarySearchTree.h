// BinarySearchTree template class
// From Weiss, "Data Structures and Algorithms in C++", 4th Edition, 2014.
// Modified for CptS 223 Spring 2022 - Homework 6
// Changes made to: 
// Order traversals, DepthEqual method

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <exception>
#include <iostream>

using namespace std;

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree( ) : root( nullptr ) {};

	BinarySearchTree( const BinarySearchTree & rhs )
	{
		root = clone( rhs.root );
	}

	~BinarySearchTree( )
	{
		makeEmpty( );
	}

	BinarySearchTree & operator=( const BinarySearchTree & rhs )
	{
		BinarySearchTree copy = rhs;
		swap( *this, copy );
		return *this;
	}

	const Comparable & findMin( ) const
	{
		if( isEmpty( ) )
			throw underflow_error("empty tree");
		return findMin( root )->element;
	}

	const Comparable & findMax( ) const
	{
		if( isEmpty( ) )
			throw underflow_error("empty tree");
		return findMax( root )->element;
	}

	bool contains( const Comparable & x ) const
	{
		return contains( x, root );
	}

	bool isEmpty( ) const
	{
		return root == nullptr;
	}

	void printTree( ostream & out = cout ) const
	{
		if( isEmpty( ) )
			out << "empty tree" << endl;
		else
			printTree( root, out );
	}

	void makeEmpty( )
	{
		makeEmpty( root );
	}

	void insert( const Comparable & x )
	{
		insert( x, root );
	}

	void remove( const Comparable & x )
	{
		remove( x, root );
	}
	
	void Traversals(ostream & out = cout)
	{
		out << "Pre-Order:";
		if( isEmpty( ) )
			out << " empty tree";
		else
			PreOrder( root, out );
		out << endl;
		out << "Post-Order:";
		if( isEmpty( ) )
			out << " empty tree";
		else
			PostOrder( root, out );
		out << endl;
		out << "In-Order:";
		if( isEmpty( ) )
			out << " empty tree";
		else
			InOrder( root, out );
		out << endl;
	}
	
	void DepthEqual(ostream & out = cout)
	{
		out << "DepthEqual:";
		if( isEmpty( ) )
			out << " empty tree";
		else
			DepthEqual( root, out );
		out << endl;
	}
	

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
		: element( theElement ), left( lt ), right( rt ) { };
	};

	BinaryNode *root;

	void insert( const Comparable & x, BinaryNode * & t )
	{
		if( t == nullptr )
			t = new BinaryNode( x, nullptr, nullptr );
		else if( x < t->element )
			insert( x, t->left );
		else if( t->element < x )
			insert( x, t->right );
		else
			;  // Duplicate; do nothing
	}

	void remove( const Comparable & x, BinaryNode * & t )
	{
		if( t == nullptr )
			return;   // Item not found; do nothing
		if( x < t->element )
			remove( x, t->left );
		else if( t->element < x )
			remove( x, t->right );
		else if( t->left != nullptr && t->right != nullptr ) { // Two children
			t->element = findMin( t->right )->element;
			remove( t->element, t->right );
		} else {
			BinaryNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			delete oldNode;
		}
	}

	BinaryNode * findMin( BinaryNode *t ) const
	{
		if( t == nullptr )
			return nullptr;
		if( t->left == nullptr )
			return t;
		return findMin( t->left );
	}

	BinaryNode * findMax( BinaryNode *t ) const
	{
		if( t != nullptr )
			while( t->right != nullptr )
				t = t->right;
		return t;
	}

	bool contains( const Comparable & x, BinaryNode *t ) const
	{
		if( t == nullptr )
			return false;
		else if( x < t->element )
			return contains( x, t->left );
		else if( t->element < x )
			return contains( x, t->right );
		else
			return true;    // Match
	}

	void makeEmpty( BinaryNode * & t )
	{
		if( t != nullptr )
		{
			makeEmpty( t->left );
			makeEmpty( t->right );
			delete t;
		}
		t = nullptr;
	}

	void printTree( BinaryNode *t, ostream & out ) const
	{
		if( t != nullptr )
		{
			printTree( t->left, out );
			out << t->element << endl;
			printTree( t->right, out );
		}
	}

	BinaryNode * clone( BinaryNode *t ) const
	{
		if( t == nullptr )
			return nullptr;
		else
			return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
	}
	
	void PreOrder( BinaryNode *t, ostream & out ) const
	{
		// out << " TODO";
		if (t != nullptr) {
			out << t->element << " ";
			PreOrder(t->left, out);
			PreOrder(t->right, out);
		}
	}

	void PostOrder( BinaryNode *t, ostream & out ) const
	{
		//out << " TODO";
		if (t != nullptr) {
			PostOrder(t->left, out);
			PostOrder(t->right, out);
			out << t->element << " ";
		}
 	}

	void InOrder( BinaryNode *t, ostream & out ) const
	{
		//out << " TODO";
		if (t != nullptr) {
			InOrder(t->left, out);
			out << t->element << " ";
			InOrder(t->right, out);
		}
	}
	
	// Assumes template class of type int
	void DepthEqual( BinaryNode *t, ostream & out, int depth = 0) const
	{
		//out << " TODO";
		if (t == nullptr) {
			return;
		}
		
		else {
			if (t->element > depth) {
				DepthEqual(t->left, out, depth + 1);
			}
			else if (t->element <= depth) {
				DepthEqual(t->right, out, depth + 1);
				if (t->element == depth) {
					out << t->element << " ";
				}
			}
		}
	}
};

#endif

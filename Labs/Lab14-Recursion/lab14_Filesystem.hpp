#ifndef Filesystem_HPP
#define Filesystem_HPP

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "StringUtil.hpp"

struct File
{
	File()
	{
		isDirectory = false;
		ptrParent = nullptr;
	}

	~File()
	{
        for ( unsigned int i = 0; i < childrenPtrs.size(); i++ )
        {
            delete childrenPtrs[i];
        }
	}

	vector<File*> childrenPtrs;
	File* ptrParent;

	bool isDirectory; // traversible
	string name;
};

class Filesystem
{
public:
    // public interfaces
    File* Find( const string& filename )
    {
        return Find( filename, m_ptrRoot );
    }

    File* GetFile( const list<string>& path, const string& filename )
    {
        return GetFile( path, filename, m_ptrRoot );
    }

private:
    //! Find a file in the filesystem tree.
    /**
        Find a file with the filename given.
        Inspect the File passed in as the ptrLookAt pointer.
        If this isn't the file we want, inspect each of this File's children.

        @param<const string&> filename  The name of the file we're searching for
        @param<File*> ptrLookAt         The file we're currently inspecting
        @return <File*>

        Example call: File* find2 = fs.Find( "file-E.txt" );
            The public Find function calls
            return Find( filename, m_ptrRoot )
    */
    File* Find( const string& filename, File* ptrLookAt )
    {
		if (filename == ptrLookAt->name)
		{
			return ptrLookAt;
		}

		if (ptrLookAt->childrenPtrs.size() == 0)
		{
			return nullptr;
		}

		for (unsigned int i = 0; i < ptrLookAt->childrenPtrs.size(); i++)
		{
			File* ret = Find(filename, ptrLookAt->childrenPtrs[i]);

			if (ret != nullptr)
			{
				return ret;
			}
		}	
		return nullptr;
    }

    //! Traverse the file path to find a specific file
    /**
        Given the path string passed in, search each directory
        for the next item in the path string and select that file node
        to traverse next until we get to the end of the path list.
        Once we're at the end of the path list, search for the filename passed in.
        Return this file once found, or nullptr if it isn't found.

        @param<list<string>> path           Path of the file ("/ROOT/folder-1/folder-E/")
        @param<const string&> filename      Name of the file ("file-E.txt")
        @param<File*> current               The current file node we're on

        Example call:
        File* getFile1 = fs.GetFile( { "ROOT", "folder-0", "folder-D" }, "file-D.txt" );
            The public GetFile function calls
            return GetFile( path, filename, m_ptrRoot );
    */
    File* GetFile( list<string> path, const string& filename, File* current )
    {
		path.pop_front();

		if (path.size() == 0)
		{
			for (unsigned int i = 0; i < current->childrenPtrs.size(); i++)
			{
				if (current->childrenPtrs[i]->name == filename)
				{
					return current->childrenPtrs[i];
				}
				return nullptr;
			}
		}

			for (unsigned int i = 0; i < current->childrenPtrs.size(); i++)
			{
				if (current->childrenPtrs[i]->name == path.front())
				{
					return GetFile(path, filename, current->childrenPtrs[i]);
				}
			
			}
		return nullptr; 
    }

public:
    // Constructor / destructor
	Filesystem()
	{
		m_nodeCount = 0;
		CreateFilesystem();
	}

	~Filesystem()
	{
        delete m_ptrRoot;
	}

    // Recursive function
	string GetPath( File* ptrFile )
	{
        if ( ptrFile == nullptr )
        {
            return "";
        }

        return GetPath( ptrFile->ptrParent ) + " / " + ptrFile->name;
	}

	// Get size
	int GetSize()
	{
        return m_nodeCount;
	}

private:
    // Create data for our lab
	void CreateFilesystem()
	{
        // Create root
        m_ptrRoot = new File;
        m_ptrRoot->isDirectory = true;
        m_ptrRoot->name = "ROOT";
        m_nodeCount++;

        cout << GetPath( m_ptrRoot ) << endl;

        // Create a few files
        for ( int i = 0; i < 3; i++ )
        {
            File* newFile = new File;
            newFile->isDirectory = false;
            newFile->name = "file-" + StringUtil::ToString( i ) + ".txt";
            newFile->ptrParent = m_ptrRoot;
            m_ptrRoot->childrenPtrs.push_back( newFile );
            m_nodeCount++;

            cout << GetPath( newFile ) << endl;
        }

        // Create a few folders
        for ( int i = 0; i < 2; i++ )
        {
            File* newFile = new File;
            newFile->isDirectory = true;
            newFile->name = "folder-" + StringUtil::ToString( i );
            newFile->ptrParent = m_ptrRoot;
            m_ptrRoot->childrenPtrs.push_back( newFile );
            m_nodeCount++;

            cout << GetPath( newFile ) << endl;
        }

        // Create files and folders for subfolders
        for ( unsigned int i = 0; i < m_ptrRoot->childrenPtrs.size(); i++ )
        {
            if ( m_ptrRoot->childrenPtrs[i]->isDirectory )
            {
                // Folder
                File* newFolder = new File;
                newFolder->isDirectory = true;
                string letter = "";
                letter += char( 65 + i );
                newFolder->name = "folder-" + letter;
                newFolder->ptrParent = m_ptrRoot->childrenPtrs[i];
                m_ptrRoot->childrenPtrs[i]->childrenPtrs.push_back( newFolder );
                m_nodeCount++;

                cout << GetPath( newFolder ) << endl;

                // Files
                for ( int i = 0; i < 3; i++ )
                {
                    File* newFile = new File;
                    newFile->isDirectory = false;
                    letter = "";
                    letter += char( 65 + i );
                    newFile->name = "file-" + letter + ".txt";
                    newFile->ptrParent = m_ptrRoot->childrenPtrs[i];
                    m_ptrRoot->childrenPtrs[i]->childrenPtrs.push_back( newFile );
                    m_nodeCount++;

                    cout << GetPath( newFile ) << endl;
                }

                // Create file in this folder
                File* newFile = new File;
                newFile->isDirectory = false;
                letter = "";
                letter += char( 65 + i );
                newFile->name = "file-" + letter + ".txt";
                newFile->ptrParent = m_ptrRoot->childrenPtrs[i]->childrenPtrs[0];
                m_ptrRoot->childrenPtrs[i]->childrenPtrs[0]->childrenPtrs.push_back( newFile );
                m_nodeCount++;

                cout << GetPath( newFile ) << endl;
            }
        }

        cout << "Total nodes: " << GetSize() << endl << endl;
	}

private:
	File* m_ptrRoot;
	int m_nodeCount;
};

#endif

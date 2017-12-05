#include "lab2_Record_Manager.HPP"

RecordManager::~RecordManager() {
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_outputs[i].is_open())
		{
			m_outputs[i].close();
		}
	}
}

void RecordManager::OpenOutputFile(string filename) {
	int index = FindAvailableFile();
	if (index < 0 || index >= MAX_FILES) {
		throw out_of_range("No Files to Open");
	}
	m_outputs[index].open(filename);
	m_filenames[index] = filename;
}

void RecordManager::CloseOutputFile(string filename) {
	int  index = FindFileNameIndex(filename);
	if (index == -1) {
		throw runtime_error("No Available Files");
	}
	m_outputs[index].close();
	m_filenames[index] = "";
}

void RecordManager::DisplayAllOpenFiles() noexcept {
	cout << "Open files: " << endl;
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_outputs[i].is_open()) {
			cout << i << ". " << m_filenames[i] << endl;
		}
	}
}

int RecordManager::FindFileNameIndex(string filename) noexcept {
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_filenames[i] == filename) {
			return i;
		}
	}
	return -1;
}

void RecordManager::WriteToFile(string filename, string text) {
	int index = FindFileNameIndex(filename);
	if (index == -1) {
		throw runtime_error("Cannot Write to File");
	}
	m_outputs[index] << text << endl;
}

int RecordManager::FindAvailableFile() noexcept {
	for (int i = 0; i < MAX_FILES; i++) {
		if (m_outputs[i].is_open() == false)
		{
			return i;
		}
	}
	return -1;
}
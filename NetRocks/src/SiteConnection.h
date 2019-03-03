#pragma once
#include <memory>
#include <string>
#include "IPC.h"

class SiteConnection : protected IPCRecver, protected IPCSender
{
	std::string _site, _site_info;

	bool IsUserRequestingAbort();

	void RecvReply(IPCCommand cmd);
	void TransactContinueOrAbort();

public:
	SiteConnection(const std::string &site, int OpMode) throw (std::runtime_error);
	virtual ~SiteConnection();
	const std::string &Site() const;
	const std::string &SiteInfo() const;

	bool IsBroken();
	void DirectoryEnum(const std::string &path, FP_SizeItemList &il, int OpMode) throw (std::runtime_error);
	mode_t GetMode(const std::string &path, bool follow_symlink = true) throw (std::runtime_error);
	unsigned long long GetSize(const std::string &path, bool follow_symlink = true) throw (std::runtime_error);
	void FileDelete(const std::string &path) throw (std::runtime_error);
	void DirectoryDelete(const std::string &path) throw (std::runtime_error);
	void DirectoryCreate(const std::string &path, mode_t mode) throw (std::runtime_error);
	void Rename(const std::string &path_old, const std::string &path_new) throw (std::runtime_error);
	void FileGet(const std::string &path_remote, const std::string &path_local, mode_t mode, unsigned long long offset = 0) throw (std::runtime_error);
	void FilePut(const std::string &path_remote, const std::string &path_local, mode_t mode, unsigned long long offset = 0) throw (std::runtime_error);
};
#include <Webserv.hpp>
#include <iostream>

//default
Webserv::Route::Route() { }

Webserv::Route::Route(bool islistingdirectory, std::string directoryfile, bool isuploadable, std::string uploadroot, std::string index, std::string root, std::string path, std::string clientmaxbodysize, std::vector<std::string> allowedHTTPmethods, std::string pythoncgiextension, std::string phpcgiextension) {
	this->islistingdirectory = islistingdirectory;
	this->directoryfile = directoryfile;
	this->isuploadable = isuploadable;
	this->uploadroot = uploadroot;
	this->index = index;
	this->root = root;
	this->path = path;
	this->clientmaxbodysize = clientmaxbodysize;
	this->allowedHTTPmethods = allowedHTTPmethods;
	this->phpcgiextension = phpcgiextension;
	this->pythoncgiextension = pythoncgiextension;
}

Webserv::Route::Route(const Route & route) {
	this->islistingdirectory = route.getListingDirectory();
	this->directoryfile = route.getDirectoryFile();
	this->index = route.getIndex();
	this->root = route.getRoot();
	this->path = route.getPath();
	this->clientmaxbodysize = route.getClientMaxBodySize();
	this->allowedHTTPmethods = route.getAllowedHTTPMethods();
	this->phpcgiextension = route.getPHPCGIExtension();
	this->pythoncgiextension = route.getPythonCGIExtension();
}

Webserv::Route::~Route() {}

Webserv::Route & Webserv::Route::operator=(const Route & route) {
	this->islistingdirectory = route.getListingDirectory();
	this->directoryfile = route.getDirectoryFile();
	this->index = route.getIndex();
	this->root = route.getRoot();
	this->path = route.getPath();
	this->clientmaxbodysize = route.getClientMaxBodySize();
	this->allowedHTTPmethods = route.getAllowedHTTPMethods();
	this->phpcgiextension = route.getPHPCGIExtension();
	this->pythoncgiextension = route.getPythonCGIExtension();
	return (*this);
}

bool			Webserv::Route::getListingDirectory() const {
	return (this->islistingdirectory);
}

std::string 	Webserv::Route::getDirectoryFile() const {
	return (this->directoryfile);
}

bool			Webserv::Route::getUploadable() const {
	return (this->isuploadable);
}

std::string 	Webserv::Route::getUploadRoot() const {
	return (this->uploadroot);
}

std::string		Webserv::Route::getIndex() const {
	return (this->index);
}

std::string		Webserv::Route::getRoot() const {
	return (this->root);
}


std::string		Webserv::Route::getPythonCGIExtension() const {
	return (this->pythoncgiextension);
}

std::string		Webserv::Route::getPHPCGIExtension() const {
	return (this->phpcgiextension);
}

std::vector<std::string> Webserv::Route::getAllowedHTTPMethods() const {
	return (this->allowedHTTPmethods);
}

std::string	Webserv::Route::getClientMaxBodySize() const {
	return (this->clientmaxbodysize);
}

std::string Webserv::Route::getPath() const {
	return (this->path);
}

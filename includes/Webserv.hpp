#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include <string>
#include <vector>
#include <JSON.hpp>

namespace Webserv {
	class Route {
		public:
			Route();
			Route(bool islistingdirectory, std::string index, std::string root,  unsigned int clientmaxbodysize, std::vector<std::string> allowedHTTPmethods);
			Route(const Route & route);
			~Route();
			Route & operator=(const Route & route);

			bool			getListingDirectory() const;
			std::string		getIndex() const;
			std::string		getRoot() const;
			std::vector<std::string> getAllowedHTTPMethods() const;
			unsigned int	getClientMaxBodySize() const;
		private:
			// is this routes directory listing its contents to the client
			bool			islistingdirectory;

			// index of the route, first file found is shown to the user
			std::string		index;

			// root directory to search for files and the like
			std::string		root;

			// what is the maximum size body that the client is alowed to send to the server
			unsigned int	clientmaxbodysize;
			
			//	Allowed http methods for the route
			std::vector<std::string>	allowedHTTPmethods;
	};

	class HandleCode {
		public:
			HandleCode(int code, Route route);
			HandleCode(const HandleCode & handlecode);
			~HandleCode();
			HandleCode & operator=(const HandleCode & handlecode);

			unsigned int	getCode() const;
			Route			getRoute() const;
			unsigned int	getResponseCode() const;
		private:
			// The HTTP code that is defined
			unsigned int			code;

			// code that is sent to the user
			unsigned int			responsecode;

			// The Route to redirect the if the code is encountered
			Route					route;

			// exception, code not recognized
			struct InvalidHTTPCode: public std::exception { const char * what () const throw () { return "Invalid Code"; } };
	};

	class Server {
		public:
			Server();
			Server(std::string servername, std::string host, unsigned int port, bool isdefault);
			Server(const Server & server);
			~Server();
			Server & operator=(const Server & server);
			
			std::string				getServerName() const;
			std::string 			getHost() const;
			unsigned int			getPort() const;
			bool					getIsDefault() const;
			std::vector<Route>		getRoutes() const;
			std::vector<HandleCode>	getHandleCode() const;
			void					addRoute(const Route & route);
			void					addCodeHandler(const HandleCode & handlecode);
			
		private:
			// Information about the server, such as its name, it's host and port, and if it's the default server for the port or not
			std::string					servername;
			std::string					host;
			unsigned int				port;
			bool						isdefault;

			// routes and error redirections associated with the server 
			std::vector<Route>			routes;
			std::vector<HandleCode>		codehandlers;
	};

	std::vector<Server> makeServersFromJSON(const JSON & json);

	static const unsigned int arr[] = {
		100, // Continue
		101, // Switching Protocols
		102, // Processing
		103, // Early Hints
		200, // OK
		201, // Created
		202, // Accepted
		203, // Non-Authorative Information
		204, // No Content
		205, // Reset Content
		206, // Partial Content
		207, // (WebDav) Multi-Status
		208, // (WebDav) Already Reported
		226, // (HTTP Delta encoding) IM used
		300, // Multiple Choices
		301, // Moved Permanenitly
		302, // Found
		303, // See Other
		304, // Not Modified
		305, // Use Proxy
		307, // Temporary Redirect
		308, // Permanent Redirect
		400, // Bad Request
		401, // Unauthorized
		402, // Payment Required 
		403, // Forbidden
		404, // Not Found
		405, // Method not Allowed
		406, // Not Exceptable
		407, // Proxy Authenitcation Required
		408, // Request Timeout
		409, // Conflict
		410, // Gone
		411, // Length Required
		412, // Precondition Failed
		413, // Payload to Large
		414, // URI to long
		415, // Unsuported Media Type
		416, // Range not Satisfiable 
		417, // Execption Failed
		418, // I'm a teapot
		421, // Misdirected Request
		422, // (WebDav) Unprocessable Entity
		423, // (WebDav) Locked
		424, // (WebDav) Failed Dependency
		425, // Too Early
		426, // Upgrade Required
		428, // Precondition Required
		429, // Too many Requests
		431, // Request Header To Large
		451, // Unavaliable for Legal Reasons
		500, // Internal Server Error
		501, // Not Implemented
		502, // Bad Gateway
		503, // Service Unavaliable
		504, // Gateway Timeout
		505, // HTTP version not supported
		506, // Varient also Negates
		507, // (WebDav) Insufficient Storage
		508, // (WebDav) Loop detected
		510, // Not Extended
		511  // Network Authentication Required
	};
	static const std::vector<unsigned int> validHTTPCodes (arr, arr + sizeof(arr) / sizeof(arr[0]) );
};

#endif
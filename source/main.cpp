#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace Poco;
using namespace Poco::Net;
using namespace std;

string PostRequest(const string &url, const string &body, const map<string, string> &headers)
{
    try
    {
        // Prepare session
        URI uri(url);
        HTTPClientSession session(uri.getHost(), uri.getPort());

        // Prepare path
        string path(uri.getPathAndQuery());
        if (path.empty())
        {
            path = "/";
        }

        // Prepare request
        HTTPRequest req(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
        req.setContentType("application/x-www-form-urlencoded");

        // Set headers
        for (auto it = headers.begin(); it != headers.end(); ++it)
        {
            req.set(it->first, it->second);
        }

        // Set content length
        req.setContentLength(body.length());

        // Print request
        req.write(cout);

        // Send request
        ostream &os = session.sendRequest(req);
        os << body;

        // Get response
        HTTPResponse res;
        cout << res.getStatus() << " " << res.getReason() << endl;

        istream &is = session.receiveResponse(res);
        stringstream ss;
        StreamCopier::copyStream(is, ss);

        return ss.str();
    }
    catch (Exception &ex)
    {
        return ex.displayText();
    }
}


int main()
{
    const string url = "http://localhost:6040";
    const string body = "hi=text";
    map<string, string> headers;
    headers["Auth"] = "Token is yours!";

    cout << "key" << endl;
    cout << PostRequest(url, body, headers) << endl;
}

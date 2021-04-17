all:
	g++ RequestModul/PageLoader.cpp RequestModul/Page.cpp Parser/HTMLParser.cpp -o Result -lcurl -lgumbo
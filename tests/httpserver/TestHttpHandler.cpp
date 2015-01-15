/*
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "TestHttpHandler.h"

#include <proxygen/httpserver/RequestHandler.h>
#include <proxygen/httpserver/ResponseBuilder.h>

using namespace proxygen;

TestHttpHandler::TestHttpHandler() {
}

void TestHttpHandler::onRequest(std::unique_ptr<HTTPMessage> headers) noexcept {
}

void TestHttpHandler::onBody(std::unique_ptr<folly::IOBuf> body) noexcept {
  if (body_) {
    body_->prependChain(std::move(body));
  } else {
    body_ = std::move(body);
  }
}

void TestHttpHandler::onEOM() noexcept {
  ResponseBuilder(downstream_)
    .status(200, "OK")
    .header("Request-Number",
            folly::to<std::string>(1))
    .body(std::move(body_))
    .sendWithEOM();
}

void TestHttpHandler::onUpgrade(UpgradeProtocol protocol) noexcept {
  // handler doesn't support upgrades
}

void TestHttpHandler::requestComplete() noexcept {
  delete this;
}

void TestHttpHandler::onError(ProxygenError err) noexcept {
  delete this;
}


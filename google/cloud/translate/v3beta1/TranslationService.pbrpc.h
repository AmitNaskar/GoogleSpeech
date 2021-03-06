#if !defined(GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO) || !GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO
#import "google/cloud/translate/v3beta1/TranslationService.pbobjc.h"
#endif

#if !defined(GPB_GRPC_PROTOCOL_ONLY) || !GPB_GRPC_PROTOCOL_ONLY
#import <ProtoRPC/ProtoService.h>
#import <ProtoRPC/ProtoRPC.h>
#import <RxLibrary/GRXWriteable.h>
#import <RxLibrary/GRXWriter.h>
#endif

@class BatchTranslateTextRequest;
@class CreateGlossaryRequest;
@class DeleteGlossaryRequest;
@class DetectLanguageRequest;
@class DetectLanguageResponse;
@class GetGlossaryRequest;
@class GetSupportedLanguagesRequest;
@class Glossary;
@class ListGlossariesRequest;
@class ListGlossariesResponse;
@class Operation;
@class SupportedLanguages;
@class TranslateTextRequest;
@class TranslateTextResponse;

#if !defined(GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO) || !GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO
  #import "google/api/Annotations.pbobjc.h"
  #import "google/longrunning/Operations.pbobjc.h"
#if defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS) && GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
  #import <Protobuf/Timestamp.pbobjc.h>
#else
  #import "google/protobuf/Timestamp.pbobjc.h"
#endif
#endif

@class GRPCProtoCall;
@class GRPCUnaryProtoCall;
@class GRPCStreamingProtoCall;
@class GRPCCallOptions;
@protocol GRPCProtoResponseHandler;


NS_ASSUME_NONNULL_BEGIN

@protocol TranslationService2 <NSObject>

#pragma mark TranslateText(TranslateTextRequest) returns (TranslateTextResponse)

/**
 * Translates input text and returns translated text.
 */
- (GRPCUnaryProtoCall *)translateTextWithMessage:(TranslateTextRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark DetectLanguage(DetectLanguageRequest) returns (DetectLanguageResponse)

/**
 * Detects the language of text within a request.
 */
- (GRPCUnaryProtoCall *)detectLanguageWithMessage:(DetectLanguageRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark GetSupportedLanguages(GetSupportedLanguagesRequest) returns (SupportedLanguages)

/**
 * Returns a list of supported languages for translation.
 */
- (GRPCUnaryProtoCall *)getSupportedLanguagesWithMessage:(GetSupportedLanguagesRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark BatchTranslateText(BatchTranslateTextRequest) returns (Operation)

/**
 * Translates a large volume of text in asynchronous batch mode.
 * This function provides real-time output as the inputs are being processed.
 * If caller cancels a request, the partial results (for an input file, it's
 * all or nothing) may still be available on the specified output location.
 * 
 * This call returns immediately and you can
 * use google.longrunning.Operation.name to poll the status of the call.
 */
- (GRPCUnaryProtoCall *)batchTranslateTextWithMessage:(BatchTranslateTextRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark CreateGlossary(CreateGlossaryRequest) returns (Operation)

/**
 * Creates a glossary and returns the long-running operation. Returns
 * NOT_FOUND, if the project doesn't exist.
 */
- (GRPCUnaryProtoCall *)createGlossaryWithMessage:(CreateGlossaryRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark ListGlossaries(ListGlossariesRequest) returns (ListGlossariesResponse)

/**
 * Lists glossaries in a project. Returns NOT_FOUND, if the project doesn't
 * exist.
 */
- (GRPCUnaryProtoCall *)listGlossariesWithMessage:(ListGlossariesRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark GetGlossary(GetGlossaryRequest) returns (Glossary)

/**
 * Gets a glossary. Returns NOT_FOUND, if the glossary doesn't
 * exist.
 */
- (GRPCUnaryProtoCall *)getGlossaryWithMessage:(GetGlossaryRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

#pragma mark DeleteGlossary(DeleteGlossaryRequest) returns (Operation)

/**
 * Deletes a glossary, or cancels glossary construction
 * if the glossary isn't created yet.
 * Returns NOT_FOUND, if the glossary doesn't exist.
 */
- (GRPCUnaryProtoCall *)deleteGlossaryWithMessage:(DeleteGlossaryRequest *)message responseHandler:(id<GRPCProtoResponseHandler>)handler callOptions:(GRPCCallOptions *_Nullable)callOptions;

@end

/**
 * The methods in this protocol belong to a set of old APIs that have been deprecated. They do not
 * recognize call options provided in the initializer. Using the v2 protocol is recommended.
 */
@protocol TranslationService <NSObject>

#pragma mark TranslateText(TranslateTextRequest) returns (TranslateTextResponse)

/**
 * Translates input text and returns translated text.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)translateTextWithRequest:(TranslateTextRequest *)request handler:(void(^)(TranslateTextResponse *_Nullable response, NSError *_Nullable error))handler;

/**
 * Translates input text and returns translated text.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToTranslateTextWithRequest:(TranslateTextRequest *)request handler:(void(^)(TranslateTextResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark DetectLanguage(DetectLanguageRequest) returns (DetectLanguageResponse)

/**
 * Detects the language of text within a request.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)detectLanguageWithRequest:(DetectLanguageRequest *)request handler:(void(^)(DetectLanguageResponse *_Nullable response, NSError *_Nullable error))handler;

/**
 * Detects the language of text within a request.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToDetectLanguageWithRequest:(DetectLanguageRequest *)request handler:(void(^)(DetectLanguageResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark GetSupportedLanguages(GetSupportedLanguagesRequest) returns (SupportedLanguages)

/**
 * Returns a list of supported languages for translation.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)getSupportedLanguagesWithRequest:(GetSupportedLanguagesRequest *)request handler:(void(^)(SupportedLanguages *_Nullable response, NSError *_Nullable error))handler;

/**
 * Returns a list of supported languages for translation.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToGetSupportedLanguagesWithRequest:(GetSupportedLanguagesRequest *)request handler:(void(^)(SupportedLanguages *_Nullable response, NSError *_Nullable error))handler;


#pragma mark BatchTranslateText(BatchTranslateTextRequest) returns (Operation)

/**
 * Translates a large volume of text in asynchronous batch mode.
 * This function provides real-time output as the inputs are being processed.
 * If caller cancels a request, the partial results (for an input file, it's
 * all or nothing) may still be available on the specified output location.
 * 
 * This call returns immediately and you can
 * use google.longrunning.Operation.name to poll the status of the call.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)batchTranslateTextWithRequest:(BatchTranslateTextRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;

/**
 * Translates a large volume of text in asynchronous batch mode.
 * This function provides real-time output as the inputs are being processed.
 * If caller cancels a request, the partial results (for an input file, it's
 * all or nothing) may still be available on the specified output location.
 * 
 * This call returns immediately and you can
 * use google.longrunning.Operation.name to poll the status of the call.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToBatchTranslateTextWithRequest:(BatchTranslateTextRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;


#pragma mark CreateGlossary(CreateGlossaryRequest) returns (Operation)

/**
 * Creates a glossary and returns the long-running operation. Returns
 * NOT_FOUND, if the project doesn't exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)createGlossaryWithRequest:(CreateGlossaryRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;

/**
 * Creates a glossary and returns the long-running operation. Returns
 * NOT_FOUND, if the project doesn't exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToCreateGlossaryWithRequest:(CreateGlossaryRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;


#pragma mark ListGlossaries(ListGlossariesRequest) returns (ListGlossariesResponse)

/**
 * Lists glossaries in a project. Returns NOT_FOUND, if the project doesn't
 * exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)listGlossariesWithRequest:(ListGlossariesRequest *)request handler:(void(^)(ListGlossariesResponse *_Nullable response, NSError *_Nullable error))handler;

/**
 * Lists glossaries in a project. Returns NOT_FOUND, if the project doesn't
 * exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToListGlossariesWithRequest:(ListGlossariesRequest *)request handler:(void(^)(ListGlossariesResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark GetGlossary(GetGlossaryRequest) returns (Glossary)

/**
 * Gets a glossary. Returns NOT_FOUND, if the glossary doesn't
 * exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)getGlossaryWithRequest:(GetGlossaryRequest *)request handler:(void(^)(Glossary *_Nullable response, NSError *_Nullable error))handler;

/**
 * Gets a glossary. Returns NOT_FOUND, if the glossary doesn't
 * exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToGetGlossaryWithRequest:(GetGlossaryRequest *)request handler:(void(^)(Glossary *_Nullable response, NSError *_Nullable error))handler;


#pragma mark DeleteGlossary(DeleteGlossaryRequest) returns (Operation)

/**
 * Deletes a glossary, or cancels glossary construction
 * if the glossary isn't created yet.
 * Returns NOT_FOUND, if the glossary doesn't exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (void)deleteGlossaryWithRequest:(DeleteGlossaryRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;

/**
 * Deletes a glossary, or cancels glossary construction
 * if the glossary isn't created yet.
 * Returns NOT_FOUND, if the glossary doesn't exist.
 *
 * This method belongs to a set of APIs that have been deprecated. Using the v2 API is recommended.
 */
- (GRPCProtoCall *)RPCToDeleteGlossaryWithRequest:(DeleteGlossaryRequest *)request handler:(void(^)(Operation *_Nullable response, NSError *_Nullable error))handler;


@end


#if !defined(GPB_GRPC_PROTOCOL_ONLY) || !GPB_GRPC_PROTOCOL_ONLY
/**
 * Basic service implementation, over gRPC, that only does
 * marshalling and parsing.
 */
@interface TranslationService : GRPCProtoService<TranslationService, TranslationService2>
- (instancetype)initWithHost:(NSString *)host callOptions:(GRPCCallOptions *_Nullable)callOptions NS_DESIGNATED_INITIALIZER;
+ (instancetype)serviceWithHost:(NSString *)host callOptions:(GRPCCallOptions *_Nullable)callOptions;
// The following methods belong to a set of old APIs that have been deprecated.
- (instancetype)initWithHost:(NSString *)host;
+ (instancetype)serviceWithHost:(NSString *)host;
@end
#endif

NS_ASSUME_NONNULL_END


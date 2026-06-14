#include "afrilang/stdlib_catalog.hpp"

namespace afrilang {
namespace {

const StdlibParamSpec kMParams_0[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"sources", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_0[] = {
    {"bfsDistances", "list number", 3, &kMParams_0[0]},
    {"bfsOrder", "list number", 3, &kMParams_0[3]},
    {"bfsReachable", "number", 3, &kMParams_0[6]},
    {"bfsLayers", "list number", 3, &kMParams_0[9]},
    {"isConnected", "bool", 2, &kMParams_0[12]},
    {"shortestPathLen", "number", 4, &kMParams_0[14]},
    {"multiSourceBfs", "list number", 3, &kMParams_0[18]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_1[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"goal", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_1[] = {
    {"dfsOrder", "list number", 3, &kMParams_1[0]},
    {"dfsRecursiveMark", "list number", 2, &kMParams_1[3]},
    {"hasCycleUndirected", "bool", 2, &kMParams_1[5]},
    {"countComponents", "number", 2, &kMParams_1[7]},
    {"topoSortDfs", "list number", 2, &kMParams_1[9]},
    {"isTree", "bool", 2, &kMParams_1[11]},
    {"dfsPathExists", "bool", 4, &kMParams_1[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_2[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_2[] = {
    {"dijkstra", "list number", 3, &kMParams_2[0]},
    {"shortestWeighted", "number", 4, &kMParams_2[3]},
    {"dijkstraPath", "list number", 4, &kMParams_2[7]},
    {"minEdgeWeight", "number", 2, &kMParams_2[11]},
    {"maxEdgeWeight", "number", 2, &kMParams_2[13]},
    {"avgEdgeWeight", "number", 2, &kMParams_2[15]},
    {"edgeCount", "number", 2, &kMParams_2[17]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_3[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_3[] = {
    {"topoSort", "list number", 2, &kMParams_3[0]},
    {"hasCycleDirected", "bool", 2, &kMParams_3[2]},
    {"inDegrees", "list number", 2, &kMParams_3[4]},
    {"outDegrees", "list number", 2, &kMParams_3[6]},
    {"sources", "list number", 2, &kMParams_3[8]},
    {"sinks", "list number", 2, &kMParams_3[10]},
    {"isDag", "bool", 2, &kMParams_3[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_4[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"a", "number"},
    {"b", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_4[] = {
    {"connectedComponents", "list number", 2, &kMParams_4[0]},
    {"componentCount", "number", 2, &kMParams_4[2]},
    {"largestComponentSize", "number", 2, &kMParams_4[4]},
    {"sameComponent", "bool", 4, &kMParams_4[6]},
    {"componentSizes", "list number", 2, &kMParams_4[10]},
    {"outDegreeSum", "list number", 2, &kMParams_4[12]},
    {"isolateCount", "number", 2, &kMParams_4[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_5[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_5[] = {
    {"detectCycleDirected", "bool", 2, &kMParams_5[0]},
    {"detectCycleUndirected", "bool", 2, &kMParams_5[2]},
    {"cycleEdgeCount", "number", 2, &kMParams_5[4]},
    {"isAcyclic", "bool", 2, &kMParams_5[6]},
    {"selfLoopCount", "number", 2, &kMParams_5[8]},
    {"removeSelfLoops", "list number", 2, &kMParams_5[10]},
    {"hasParallelEdges", "bool", 2, &kMParams_5[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_6[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_6[] = {
    {"mstWeightPrim", "number", 2, &kMParams_6[0]},
    {"mstWeightKruskal", "number", 2, &kMParams_6[2]},
    {"mstEdges", "number", 2, &kMParams_6[4]},
    {"compareMstAlgos", "number", 2, &kMParams_6[6]},
    {"forestMstWeight", "number", 2, &kMParams_6[8]},
    {"isConnectedForMst", "bool", 2, &kMParams_6[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_7[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_7[] = {
    {"allPairsBfs", "list number", 2, &kMParams_7[0]},
    {"eccentricity", "list number", 2, &kMParams_7[2]},
    {"graphDiameter", "number", 2, &kMParams_7[4]},
    {"graphRadius", "number", 2, &kMParams_7[6]},
    {"centerNodes", "list number", 2, &kMParams_7[8]},
    {"peripheryNodes", "list number", 2, &kMParams_7[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_8[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"dist", "list number"},
    {"adj", "list number"},
    {"n", "number"},
    {"path", "list number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_8[] = {
    {"bellmanFord", "list number", 3, &kMParams_8[0]},
    {"hasNegCycle", "bool", 2, &kMParams_8[3]},
    {"negEdgeCount", "number", 2, &kMParams_8[5]},
    {"relaxOnce", "list number", 3, &kMParams_8[7]},
    {"pathCost", "number", 3, &kMParams_8[10]},
    {"reachableWeighted", "number", 3, &kMParams_8[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_9[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"a", "number"},
    {"b", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_9[] = {
    {"floydWarshall", "list number", 2, &kMParams_9[0]},
    {"pairDistance", "number", 4, &kMParams_9[2]},
    {"closureReachable", "list number", 2, &kMParams_9[6]},
    {"graphDensity", "number", 2, &kMParams_9[8]},
    {"avgShortestPath", "number", 2, &kMParams_9[10]},
    {"transitiveClosure", "list number", 2, &kMParams_9[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_10[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_10[] = {
    {"primMst", "number", 2, &kMParams_10[0]},
    {"primParents", "list number", 2, &kMParams_10[2]},
    {"primOrder", "list number", 2, &kMParams_10[4]},
    {"mstEdgeCount", "number", 2, &kMParams_10[6]},
    {"lightestEdge", "number", 2, &kMParams_10[8]},
    {"heaviestMstEdge", "number", 2, &kMParams_10[10]},
    {"isPrimConnected", "bool", 2, &kMParams_10[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_11[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_11[] = {
    {"kruskalMst", "number", 2, &kMParams_11[0]},
    {"kruskalEdges", "list number", 2, &kMParams_11[2]},
    {"unionFindComponents", "number", 2, &kMParams_11[4]},
    {"edgeListSize", "number", 2, &kMParams_11[6]},
    {"kruskalForestWeight", "number", 2, &kMParams_11[8]},
    {"maxSpanningForest", "number", 2, &kMParams_11[10]},
    {"compareKruskalPrim", "number", 2, &kMParams_11[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_12[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_12[] = {
    {"isBipartite", "bool", 2, &kMParams_12[0]},
    {"bipartiteColors", "list number", 2, &kMParams_12[2]},
    {"partitionSizes", "list number", 2, &kMParams_12[4]},
    {"crossEdgeCount", "number", 2, &kMParams_12[6]},
    {"sameSideEdges", "number", 2, &kMParams_12[8]},
    {"bipartiteDensity", "number", 2, &kMParams_12[10]},
    {"hasOddCycle", "bool", 2, &kMParams_12[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_13[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_13[] = {
    {"vertexDegrees", "list number", 2, &kMParams_13[0]},
    {"hasEulerCircuit", "bool", 2, &kMParams_13[2]},
    {"hasEulerPath", "bool", 2, &kMParams_13[4]},
    {"oddDegreeCount", "number", 2, &kMParams_13[6]},
    {"totalDegree", "number", 2, &kMParams_13[8]},
    {"eulerTrailLen", "number", 2, &kMParams_13[10]},
    {"isEulerian", "bool", 2, &kMParams_13[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_14[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_14[] = {
    {"hamiltonianExists", "bool", 2, &kMParams_14[0]},
    {"permuteCheck", "number", 2, &kMParams_14[2]},
    {"longestPath", "number", 2, &kMParams_14[4]},
    {"hamiltonianCycle", "bool", 2, &kMParams_14[6]},
    {"pathCoverSize", "number", 2, &kMParams_14[8]},
    {"tspLowerBound", "number", 2, &kMParams_14[10]},
    {"nearestNeighbor", "list number", 3, &kMParams_14[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_15[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"nodes", "list number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_15[] = {
    {"maxCliqueSize", "number", 2, &kMParams_15[0]},
    {"cliqueNumber", "number", 2, &kMParams_15[2]},
    {"isClique", "bool", 3, &kMParams_15[4]},
    {"cliqueCover", "number", 2, &kMParams_15[7]},
    {"triangleCount", "number", 2, &kMParams_15[9]},
    {"clusteringCoeff", "list number", 2, &kMParams_15[11]},
    {"density", "number", 2, &kMParams_15[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_16[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"colors", "list number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"colors", "list number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"node", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_16[] = {
    {"greedyColor", "list number", 2, &kMParams_16[0]},
    {"chromaticNumber", "number", 2, &kMParams_16[2]},
    {"isValidColoring", "bool", 3, &kMParams_16[4]},
    {"colorClasses", "list number", 2, &kMParams_16[7]},
    {"conflictCount", "number", 3, &kMParams_16[9]},
    {"welshPowell", "list number", 2, &kMParams_16[12]},
    {"sameColorNeighbors", "number", 3, &kMParams_16[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_17[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"source", "number"},
    {"sink", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"source", "number"},
    {"sink", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"source", "number"},
    {"sink", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"node", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"node", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"source", "number"},
    {"sink", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_17[] = {
    {"maxFlow", "number", 4, &kMParams_17[0]},
    {"minCutValue", "number", 4, &kMParams_17[4]},
    {"flowMatrix", "list number", 4, &kMParams_17[8]},
    {"bottleneckCapacity", "number", 2, &kMParams_17[12]},
    {"outFlowSum", "number", 3, &kMParams_17[14]},
    {"inFlowSum", "number", 3, &kMParams_17[17]},
    {"isFlowConserved", "bool", 4, &kMParams_17[20]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_18[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"node", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_18[] = {
    {"maxMatching", "number", 2, &kMParams_18[0]},
    {"matchingPairs", "list number", 2, &kMParams_18[2]},
    {"isPerfectMatching", "bool", 2, &kMParams_18[4]},
    {"unmatchedCount", "number", 2, &kMParams_18[6]},
    {"matchingWeight", "number", 2, &kMParams_18[8]},
    {"vertexCoverSize", "number", 2, &kMParams_18[10]},
    {"isMatched", "bool", 3, &kMParams_18[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_19[] = {
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"damping", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {"adj", "list number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_19[] = {
    {"degreeCentrality", "list number", 2, &kMParams_19[0]},
    {"closenessCentrality", "list number", 2, &kMParams_19[2]},
    {"betweennessApprox", "list number", 2, &kMParams_19[4]},
    {"eigenvectorCentrality", "list number", 2, &kMParams_19[6]},
    {"pageRank", "list number", 3, &kMParams_19[8]},
    {"hubScore", "list number", 2, &kMParams_19[11]},
    {"mostCentral", "number", 2, &kMParams_19[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_20[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"x", "list number"},
    {"y", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_20[] = {
    {"regSum", "number", 1, &kMParams_20[0]},
    {"regMean", "number", 1, &kMParams_20[1]},
    {"regMin", "number", 1, &kMParams_20[2]},
    {"regMax", "number", 1, &kMParams_20[3]},
    {"regVar", "number", 1, &kMParams_20[4]},
    {"regStd", "number", 1, &kMParams_20[5]},
    {"regNorm", "list number", 1, &kMParams_20[6]},
    {"linearRegress", "list number", 2, &kMParams_20[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_21[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"lag", "number"},
    {"v", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"c", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_21[] = {
    {"pearson", "number", 2, &kMParams_21[0]},
    {"covariance", "number", 2, &kMParams_21[2]},
    {"crossCorr", "number", 3, &kMParams_21[4]},
    {"autocorr1", "number", 1, &kMParams_21[7]},
    {"partialCorr", "number", 3, &kMParams_21[8]},
    {"corrMatrix2", "list number", 2, &kMParams_21[11]},
    {"rankCorr", "number", 2, &kMParams_21[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_22[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_22[] = {
    {"q1", "number", 1, &kMParams_22[0]},
    {"q2", "number", 1, &kMParams_22[1]},
    {"q3", "number", 1, &kMParams_22[2]},
    {"iqr", "number", 1, &kMParams_22[3]},
    {"quartiles", "list number", 1, &kMParams_22[4]},
    {"fiveNum", "list number", 1, &kMParams_22[5]},
    {"outlierFence", "list number", 1, &kMParams_22[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_23[] = {
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_23[] = {
    {"histogram", "list number", 2, &kMParams_23[0]},
    {"binEdges", "list number", 2, &kMParams_23[2]},
    {"freqDensity", "list number", 2, &kMParams_23[4]},
    {"cumFreq", "list number", 2, &kMParams_23[6]},
    {"modeBin", "number", 2, &kMParams_23[8]},
    {"binWidth", "number", 2, &kMParams_23[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_24[] = {
    {"groups", "list number"},
    {"labels", "list number"},
    {"v", "list number"},
    {"groups", "list number"},
    {"labels", "list number"},
    {"groups", "list number"},
    {"labels", "list number"},
    {"groups", "list number"},
    {"labels", "list number"},
    {"groups", "list number"},
    {"labels", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_24[] = {
    {"groupMeans", "list number", 2, &kMParams_24[0]},
    {"grandMean", "number", 1, &kMParams_24[2]},
    {"betweenSS", "number", 2, &kMParams_24[3]},
    {"withinSS", "number", 2, &kMParams_24[5]},
    {"fStatistic", "number", 2, &kMParams_24[7]},
    {"etaSquared", "number", 2, &kMParams_24[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_25[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_25[] = {
    {"tStatistic", "number", 2, &kMParams_25[0]},
    {"pooledVariance", "number", 2, &kMParams_25[2]},
    {"cohenD", "number", 2, &kMParams_25[4]},
    {"meanDiff", "number", 2, &kMParams_25[6]},
    {"welchT", "number", 2, &kMParams_25[8]},
    {"effectSize", "number", 2, &kMParams_25[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_26[] = {
    {"observed", "list number"},
    {"expected", "list number"},
    {"chi2", "number"},
    {"n", "number"},
    {"k", "number"},
    {"total", "number"},
    {"bins", "number"},
    {"observed", "list number"},
    {"expected", "list number"},
    {"observed", "list number"},
    {"expected", "list number"},
    {"bins", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_26[] = {
    {"chi2Stat", "number", 2, &kMParams_26[0]},
    {"cramersV", "number", 3, &kMParams_26[2]},
    {"expectedUniform", "list number", 2, &kMParams_26[5]},
    {"goodnessOfFit", "number", 2, &kMParams_26[7]},
    {"residuals", "list number", 2, &kMParams_26[9]},
    {"df", "number", 1, &kMParams_26[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_27[] = {
    {"x", "number"},
    {"mu", "number"},
    {"sigma", "number"},
    {"x", "number"},
    {"mu", "number"},
    {"sigma", "number"},
    {"p", "number"},
    {"x", "number"},
    {"mu", "number"},
    {"sigma", "number"},
    {"data", "list number"},
    {"mu", "number"},
    {"sigma", "number"},
    {"x", "number"},
    {"y", "number"},
    {"rho", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_27[] = {
    {"normPdf", "number", 3, &kMParams_27[0]},
    {"normCdfApprox", "number", 3, &kMParams_27[3]},
    {"zFromP", "number", 1, &kMParams_27[6]},
    {"standardize", "number", 3, &kMParams_27[7]},
    {"logLikelihood", "number", 3, &kMParams_27[10]},
    {"bivariatePdf", "number", 3, &kMParams_27[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_28[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"val", "number"},
    {"v", "list number"},
    {"val", "number"},
    {"threshold", "number"},
    {"v", "list number"},
    {"z", "list number"},
    {"mean", "number"},
    {"stddev", "number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_28[] = {
    {"zScores", "list number", 1, &kMParams_28[0]},
    {"zScore", "number", 2, &kMParams_28[1]},
    {"isOutlierZ", "bool", 3, &kMParams_28[3]},
    {"standardize", "list number", 1, &kMParams_28[6]},
    {"destandardize", "list number", 3, &kMParams_28[7]},
    {"zMean", "number", 1, &kMParams_28[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_29[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_29[] = {
    {"covSum", "number", 1, &kMParams_29[0]},
    {"covMean", "number", 1, &kMParams_29[1]},
    {"covMin", "number", 1, &kMParams_29[2]},
    {"covMax", "number", 1, &kMParams_29[3]},
    {"covVar", "number", 1, &kMParams_29[4]},
    {"covStd", "number", 1, &kMParams_29[5]},
    {"covNorm", "list number", 1, &kMParams_29[6]},
    {"covariance", "number", 2, &kMParams_29[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_30[] = {
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_30[] = {
    {"rmse", "number", 2, &kMParams_30[0]},
    {"mse", "number", 2, &kMParams_30[2]},
    {"mae", "number", 2, &kMParams_30[4]},
    {"nrmse", "number", 2, &kMParams_30[6]},
    {"smape", "number", 2, &kMParams_30[8]},
    {"r2Score", "number", 2, &kMParams_30[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_31[] = {
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {"actual", "list number"},
    {"predicted", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_31[] = {
    {"mape", "number", 2, &kMParams_31[0]},
    {"wape", "number", 2, &kMParams_31[2]},
    {"smape", "number", 2, &kMParams_31[4]},
    {"bias", "number", 2, &kMParams_31[6]},
    {"trackingSignal", "number", 2, &kMParams_31[8]},
    {"forecastError", "list number", 2, &kMParams_31[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_32[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"pct", "number"},
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"w", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_32[] = {
    {"median", "number", 1, &kMParams_32[0]},
    {"medAbsDev", "number", 1, &kMParams_32[1]},
    {"trimmedMean", "number", 2, &kMParams_32[2]},
    {"movingMedian", "list number", 2, &kMParams_32[4]},
    {"weightedMedian", "number", 2, &kMParams_32[6]},
    {"medianDiff", "number", 2, &kMParams_32[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_33[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_33[] = {
    {"mode", "number", 1, &kMParams_33[0]},
    {"modeCount", "number", 1, &kMParams_33[1]},
    {"multimodal", "bool", 1, &kMParams_33[2]},
    {"uniqueCount", "number", 1, &kMParams_33[3]},
    {"entropy", "number", 1, &kMParams_33[4]},
    {"giniSimpson", "number", 1, &kMParams_33[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_34[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_34[] = {
    {"skewness", "number", 1, &kMParams_34[0]},
    {"kurtosisExcess", "number", 1, &kMParams_34[1]},
    {"moment3", "number", 1, &kMParams_34[2]},
    {"moment4", "number", 1, &kMParams_34[3]},
    {"jarqueBera", "number", 1, &kMParams_34[4]},
    {"isSymmetric", "bool", 1, &kMParams_34[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_35[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_35[] = {
    {"kurtosis", "number", 1, &kMParams_35[0]},
    {"excessKurtosis", "number", 1, &kMParams_35[1]},
    {"isLeptokurtic", "bool", 1, &kMParams_35[2]},
    {"isPlatykurtic", "bool", 1, &kMParams_35[3]},
    {"tailRatio", "number", 1, &kMParams_35[4]},
    {"peakedness", "number", 1, &kMParams_35[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_36[] = {
    {"v", "list number"},
    {"samples", "number"},
    {"v", "list number"},
    {"samples", "number"},
    {"v", "list number"},
    {"size", "number"},
    {"v", "list number"},
    {"samples", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"stat", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_36[] = {
    {"bootstrapMean", "number", 2, &kMParams_36[0]},
    {"bootstrapSE", "number", 2, &kMParams_36[2]},
    {"resample", "list number", 2, &kMParams_36[4]},
    {"bootstrapCI", "list number", 2, &kMParams_36[6]},
    {"jackknife", "list number", 1, &kMParams_36[8]},
    {"biasCorrected", "number", 2, &kMParams_36[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_37[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"threshold", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"pct", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"val", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_37[] = {
    {"iqrOutliers", "list number", 1, &kMParams_37[0]},
    {"zOutliers", "list number", 2, &kMParams_37[1]},
    {"outlierCount", "number", 1, &kMParams_37[3]},
    {"winsorize", "list number", 2, &kMParams_37[4]},
    {"modifiedZ", "list number", 1, &kMParams_37[6]},
    {"isOutlier", "bool", 2, &kMParams_37[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_38[] = {
    {"v", "list number"},
    {"p", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"val", "number"},
    {"v", "list number"},
    {"d", "number"},
    {"v", "list number"},
    {"q", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_38[] = {
    {"percentile", "number", 2, &kMParams_38[0]},
    {"percentiles", "list number", 1, &kMParams_38[2]},
    {"rankPct", "number", 2, &kMParams_38[3]},
    {"decile", "number", 2, &kMParams_38[5]},
    {"quantile", "number", 2, &kMParams_38[7]},
    {"p90", "number", 1, &kMParams_38[9]},
    {"p99", "number", 1, &kMParams_38[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_39[] = {
    {"prior", "number"},
    {"likelihood", "number"},
    {"evidence", "number"},
    {"priorOdds", "number"},
    {"likelihoodRatio", "number"},
    {"odds", "number"},
    {"prior", "number"},
    {"likelihoodH1", "number"},
    {"likelihoodH0", "number"},
    {"samples", "list number"},
    {"losses", "list number"},
    {"probs", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_39[] = {
    {"bayesUpdate", "number", 3, &kMParams_39[0]},
    {"posteriorOdds", "number", 2, &kMParams_39[3]},
    {"priorFromOdds", "number", 1, &kMParams_39[5]},
    {"oddsFromPrior", "number", 1, &kMParams_39[6]},
    {"bayesFactor", "number", 2, &kMParams_39[7]},
    {"credibleInterval", "list number", 1, &kMParams_39[9]},
    {"expectedLoss", "number", 2, &kMParams_39[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_40[] = {
    {"points", "list number"},
    {"k", "number"},
    {"dims", "number"},
    {"points", "list number"},
    {"centroids", "list number"},
    {"dims", "number"},
    {"points", "list number"},
    {"centroids", "list number"},
    {"dims", "number"},
    {"labels", "list number"},
    {"k", "number"},
    {"points", "list number"},
    {"labels", "list number"},
    {"idx", "number"},
    {"dims", "number"},
    {"points", "list number"},
    {"maxK", "number"},
    {"dims", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_40[] = {
    {"kmeans", "list number", 3, &kMParams_40[0]},
    {"assignClusters", "list number", 3, &kMParams_40[3]},
    {"inertia", "number", 3, &kMParams_40[6]},
    {"clusterSizes", "list number", 2, &kMParams_40[9]},
    {"silhouetteSample", "number", 4, &kMParams_40[11]},
    {"elbowK", "number", 3, &kMParams_40[15]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_41[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"weights", "list number"},
    {"features", "list number"},
    {"bias", "number"},
    {"weights", "list number"},
    {"X", "list number"},
    {"y", "list number"},
    {"dims", "number"},
    {"weights", "list number"},
    {"X", "list number"},
    {"y", "list number"},
    {"lr", "number"},
    {"dims", "number"},
    {"weights", "list number"},
    {"X", "list number"},
    {"y", "list number"},
    {"lr", "number"},
    {"epochs", "number"},
    {"dims", "number"},
    {"x", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_41[] = {
    {"dot", "number", 2, &kMParams_41[0]},
    {"predict", "number", 3, &kMParams_41[2]},
    {"mse", "number", 4, &kMParams_41[5]},
    {"gradientStep", "list number", 5, &kMParams_41[9]},
    {"trainEpochs", "list number", 6, &kMParams_41[14]},
    {"sigmoid", "number", 1, &kMParams_41[20]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_42[] = {
    {"labels", "list number"},
    {"cls", "number"},
    {"features", "list number"},
    {"labels", "list number"},
    {"cls", "number"},
    {"feat", "number"},
    {"features", "list number"},
    {"labels", "list number"},
    {"cls", "number"},
    {"x", "number"},
    {"mu", "number"},
    {"sigma", "number"},
    {"features", "list number"},
    {"trainX", "list number"},
    {"trainY", "list number"},
    {"numClasses", "number"},
    {"features", "list number"},
    {"trainX", "list number"},
    {"trainY", "list number"},
    {"cls", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_42[] = {
    {"classPrior", "number", 2, &kMParams_42[0]},
    {"featureMean", "number", 4, &kMParams_42[2]},
    {"featureVar", "number", 3, &kMParams_42[6]},
    {"gaussianLikelihood", "number", 3, &kMParams_42[9]},
    {"predictClass", "number", 4, &kMParams_42[12]},
    {"logPosterior", "number", 4, &kMParams_42[16]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_43[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_43[] = {
    {"tfidSum", "number", 1, &kMParams_43[0]},
    {"tfidMean", "number", 1, &kMParams_43[1]},
    {"tfidMin", "number", 1, &kMParams_43[2]},
    {"tfidMax", "number", 1, &kMParams_43[3]},
    {"tfidVar", "number", 1, &kMParams_43[4]},
    {"tfidStd", "number", 1, &kMParams_43[5]},
    {"tfidNorm", "list number", 1, &kMParams_43[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_44[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"v", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"query", "list number"},
    {"matrix", "list number"},
    {"dims", "number"},
    {"query", "list number"},
    {"matrix", "list number"},
    {"dims", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_44[] = {
    {"cosineSim", "number", 2, &kMParams_44[0]},
    {"cosineDist", "number", 2, &kMParams_44[2]},
    {"normalize", "list number", 1, &kMParams_44[4]},
    {"angularDist", "number", 2, &kMParams_44[5]},
    {"batchCosine", "list number", 3, &kMParams_44[7]},
    {"mostSimilar", "number", 3, &kMParams_44[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_45[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_45[] = {
    {"svmSum", "number", 1, &kMParams_45[0]},
    {"svmMean", "number", 1, &kMParams_45[1]},
    {"svmMin", "number", 1, &kMParams_45[2]},
    {"svmMax", "number", 1, &kMParams_45[3]},
    {"svmVar", "number", 1, &kMParams_45[4]},
    {"svmStd", "number", 1, &kMParams_45[5]},
    {"svmNorm", "list number", 1, &kMParams_45[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_46[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_46[] = {
    {"pcaSum", "number", 1, &kMParams_46[0]},
    {"pcaMean", "number", 1, &kMParams_46[1]},
    {"pcaMin", "number", 1, &kMParams_46[2]},
    {"pcaMax", "number", 1, &kMParams_46[3]},
    {"pcaVar", "number", 1, &kMParams_46[4]},
    {"pcaStd", "number", 1, &kMParams_46[5]},
    {"pcaNorm", "list number", 1, &kMParams_46[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_47[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_47[] = {
    {"entrSum", "number", 1, &kMParams_47[0]},
    {"entrMean", "number", 1, &kMParams_47[1]},
    {"entrMin", "number", 1, &kMParams_47[2]},
    {"entrMax", "number", 1, &kMParams_47[3]},
    {"entrVar", "number", 1, &kMParams_47[4]},
    {"entrStd", "number", 1, &kMParams_47[5]},
    {"entrNorm", "list number", 1, &kMParams_47[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_48[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_48[] = {
    {"kldiSum", "number", 1, &kMParams_48[0]},
    {"kldiMean", "number", 1, &kMParams_48[1]},
    {"kldiMin", "number", 1, &kMParams_48[2]},
    {"kldiMax", "number", 1, &kMParams_48[3]},
    {"kldiVar", "number", 1, &kMParams_48[4]},
    {"kldiStd", "number", 1, &kMParams_48[5]},
    {"kldiNorm", "list number", 1, &kMParams_48[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_49[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_49[] = {
    {"gradSum", "number", 1, &kMParams_49[0]},
    {"gradMean", "number", 1, &kMParams_49[1]},
    {"gradMin", "number", 1, &kMParams_49[2]},
    {"gradMax", "number", 1, &kMParams_49[3]},
    {"gradVar", "number", 1, &kMParams_49[4]},
    {"gradStd", "number", 1, &kMParams_49[5]},
    {"gradNorm", "list number", 1, &kMParams_49[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_50[] = {
    {"logits", "list number"},
    {"probs", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"idx", "number"},
    {"size", "number"},
    {"logits", "list number"},
    {"probs", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_50[] = {
    {"softmax", "list number", 1, &kMParams_50[0]},
    {"crossEntropy", "number", 2, &kMParams_50[1]},
    {"argmax", "number", 1, &kMParams_50[3]},
    {"oneHot", "list number", 2, &kMParams_50[4]},
    {"logSoftmax", "list number", 1, &kMParams_50[6]},
    {"entropy", "number", 1, &kMParams_50[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_51[] = {
    {"weights", "list number"},
    {"features", "list number"},
    {"bias", "number"},
    {"weights", "list number"},
    {"bias", "number"},
    {"features", "list number"},
    {"label", "number"},
    {"lr", "number"},
    {"weights", "list number"},
    {"bias", "number"},
    {"X", "list number"},
    {"y", "list number"},
    {"dims", "number"},
    {"weights", "list number"},
    {"features", "list number"},
    {"label", "number"},
    {"bias", "number"},
    {"size", "number"},
    {"weights", "list number"},
    {"bias", "number"},
    {"X", "list number"},
    {"y", "list number"},
    {"lr", "number"},
    {"dims", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_51[] = {
    {"predict", "number", 3, &kMParams_51[0]},
    {"trainStep", "list number", 5, &kMParams_51[3]},
    {"accuracy", "number", 5, &kMParams_51[8]},
    {"hingeLoss", "number", 4, &kMParams_51[13]},
    {"initWeights", "list number", 1, &kMParams_51[17]},
    {"trainEpoch", "list number", 6, &kMParams_51[18]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_52[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_52[] = {
    {"crosSum", "number", 1, &kMParams_52[0]},
    {"crosMean", "number", 1, &kMParams_52[1]},
    {"crosMin", "number", 1, &kMParams_52[2]},
    {"crosMax", "number", 1, &kMParams_52[3]},
    {"crosVar", "number", 1, &kMParams_52[4]},
    {"crosStd", "number", 1, &kMParams_52[5]},
    {"crosNorm", "list number", 1, &kMParams_52[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_53[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_53[] = {
    {"featSum", "number", 1, &kMParams_53[0]},
    {"featMean", "number", 1, &kMParams_53[1]},
    {"featMin", "number", 1, &kMParams_53[2]},
    {"featMax", "number", 1, &kMParams_53[3]},
    {"featVar", "number", 1, &kMParams_53[4]},
    {"featStd", "number", 1, &kMParams_53[5]},
    {"featNorm", "list number", 1, &kMParams_53[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_54[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_54[] = {
    {"normSum", "number", 1, &kMParams_54[0]},
    {"normMean", "number", 1, &kMParams_54[1]},
    {"normMin", "number", 1, &kMParams_54[2]},
    {"normMax", "number", 1, &kMParams_54[3]},
    {"normVar", "number", 1, &kMParams_54[4]},
    {"normStd", "number", 1, &kMParams_54[5]},
    {"normNorm", "list number", 1, &kMParams_54[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_55[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_55[] = {
    {"distSum", "number", 1, &kMParams_55[0]},
    {"distMean", "number", 1, &kMParams_55[1]},
    {"distMin", "number", 1, &kMParams_55[2]},
    {"distMax", "number", 1, &kMParams_55[3]},
    {"distVar", "number", 1, &kMParams_55[4]},
    {"distStd", "number", 1, &kMParams_55[5]},
    {"distNorm", "list number", 1, &kMParams_55[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_56[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_56[] = {
    {"clusSum", "number", 1, &kMParams_56[0]},
    {"clusMean", "number", 1, &kMParams_56[1]},
    {"clusMin", "number", 1, &kMParams_56[2]},
    {"clusMax", "number", 1, &kMParams_56[3]},
    {"clusVar", "number", 1, &kMParams_56[4]},
    {"clusStd", "number", 1, &kMParams_56[5]},
    {"clusNorm", "list number", 1, &kMParams_56[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_57[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_57[] = {
    {"nearSum", "number", 1, &kMParams_57[0]},
    {"nearMean", "number", 1, &kMParams_57[1]},
    {"nearMin", "number", 1, &kMParams_57[2]},
    {"nearMax", "number", 1, &kMParams_57[3]},
    {"nearVar", "number", 1, &kMParams_57[4]},
    {"nearStd", "number", 1, &kMParams_57[5]},
    {"nearNorm", "list number", 1, &kMParams_57[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_58[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_58[] = {
    {"deciSum", "number", 1, &kMParams_58[0]},
    {"deciMean", "number", 1, &kMParams_58[1]},
    {"deciMin", "number", 1, &kMParams_58[2]},
    {"deciMax", "number", 1, &kMParams_58[3]},
    {"deciVar", "number", 1, &kMParams_58[4]},
    {"deciStd", "number", 1, &kMParams_58[5]},
    {"deciNorm", "list number", 1, &kMParams_58[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_59[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_59[] = {
    {"enseSum", "number", 1, &kMParams_59[0]},
    {"enseMean", "number", 1, &kMParams_59[1]},
    {"enseMin", "number", 1, &kMParams_59[2]},
    {"enseMax", "number", 1, &kMParams_59[3]},
    {"enseVar", "number", 1, &kMParams_59[4]},
    {"enseStd", "number", 1, &kMParams_59[5]},
    {"enseNorm", "list number", 1, &kMParams_59[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_60[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_60[] = {
    {"sha2Len", "number", 1, &kMParams_60[0]},
    {"sha2Upper", "text", 1, &kMParams_60[1]},
    {"sha2Lower", "text", 1, &kMParams_60[2]},
    {"sha2Trim", "text", 1, &kMParams_60[3]},
    {"sha2Split", "list text", 2, &kMParams_60[4]},
    {"sha2Join", "text", 2, &kMParams_60[6]},
    {"sha2Replace", "text", 3, &kMParams_60[8]},
    {"hash32", "number", 1, &kMParams_60[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_61[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_61[] = {
    {"sha1Len", "number", 1, &kMParams_61[0]},
    {"sha1Upper", "text", 1, &kMParams_61[1]},
    {"sha1Lower", "text", 1, &kMParams_61[2]},
    {"sha1Trim", "text", 1, &kMParams_61[3]},
    {"sha1Split", "list text", 2, &kMParams_61[4]},
    {"sha1Join", "text", 2, &kMParams_61[6]},
    {"sha1Replace", "text", 3, &kMParams_61[8]},
    {"hash32", "number", 1, &kMParams_61[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_62[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_62[] = {
    {"md5Len", "number", 1, &kMParams_62[0]},
    {"md5Upper", "text", 1, &kMParams_62[1]},
    {"md5Lower", "text", 1, &kMParams_62[2]},
    {"md5Trim", "text", 1, &kMParams_62[3]},
    {"md5Split", "list text", 2, &kMParams_62[4]},
    {"md5Join", "text", 2, &kMParams_62[6]},
    {"md5Replace", "text", 3, &kMParams_62[8]},
    {"hash32", "number", 1, &kMParams_62[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_63[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_63[] = {
    {"hmacLen", "number", 1, &kMParams_63[0]},
    {"hmacUpper", "text", 1, &kMParams_63[1]},
    {"hmacLower", "text", 1, &kMParams_63[2]},
    {"hmacTrim", "text", 1, &kMParams_63[3]},
    {"hmacSplit", "list text", 2, &kMParams_63[4]},
    {"hmacJoin", "text", 2, &kMParams_63[6]},
    {"hmacReplace", "text", 3, &kMParams_63[8]},
    {"hash32", "number", 1, &kMParams_63[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_64[] = {
    {"a", "text"},
    {"b", "text"},
    {"hex", "text"},
    {"key", "text"},
    {"data", "text"},
    {"key", "text"},
    {"a", "list number"},
    {"b", "list number"},
    {"s", "text"},
    {"data", "list number"},
    {"key", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_64[] = {
    {"xorBytes", "text", 2, &kMParams_64[0]},
    {"xorHex", "text", 2, &kMParams_64[2]},
    {"repeatKey", "text", 2, &kMParams_64[4]},
    {"xorList", "list number", 2, &kMParams_64[6]},
    {"parity", "number", 1, &kMParams_64[8]},
    {"rollingXor", "list number", 2, &kMParams_64[9]},
    {"selfXor", "text", 1, &kMParams_64[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_65[] = {
    {"s", "text"},
    {"shift", "number"},
    {"s", "text"},
    {"shift", "number"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"plain", "text"},
    {"cipher", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_65[] = {
    {"encrypt", "text", 2, &kMParams_65[0]},
    {"decrypt", "text", 2, &kMParams_65[2]},
    {"bruteForce", "list text", 1, &kMParams_65[4]},
    {"countAlpha", "number", 1, &kMParams_65[5]},
    {"rotAll", "list text", 1, &kMParams_65[6]},
    {"isCaesar", "bool", 2, &kMParams_65[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_66[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_66[] = {
    {"vigeLen", "number", 1, &kMParams_66[0]},
    {"vigeUpper", "text", 1, &kMParams_66[1]},
    {"vigeLower", "text", 1, &kMParams_66[2]},
    {"vigeTrim", "text", 1, &kMParams_66[3]},
    {"vigeSplit", "list text", 2, &kMParams_66[4]},
    {"vigeJoin", "text", 2, &kMParams_66[6]},
    {"vigeReplace", "text", 3, &kMParams_66[8]},
    {"hash32", "number", 1, &kMParams_66[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_67[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_67[] = {
    {"encode", "text", 1, &kMParams_67[0]},
    {"decode", "text", 1, &kMParams_67[1]},
    {"isValid", "bool", 1, &kMParams_67[2]},
    {"paddedLen", "number", 1, &kMParams_67[3]},
    {"roundTrip", "bool", 1, &kMParams_67[4]},
    {"urlSafe", "text", 1, &kMParams_67[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_68[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_68[] = {
    {"rot1Len", "number", 1, &kMParams_68[0]},
    {"rot1Upper", "text", 1, &kMParams_68[1]},
    {"rot1Lower", "text", 1, &kMParams_68[2]},
    {"rot1Trim", "text", 1, &kMParams_68[3]},
    {"rot1Split", "list text", 2, &kMParams_68[4]},
    {"rot1Join", "text", 2, &kMParams_68[6]},
    {"rot1Replace", "text", 3, &kMParams_68[8]},
    {"hash32", "number", 1, &kMParams_68[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_69[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_69[] = {
    {"aeslLen", "number", 1, &kMParams_69[0]},
    {"aeslUpper", "text", 1, &kMParams_69[1]},
    {"aeslLower", "text", 1, &kMParams_69[2]},
    {"aeslTrim", "text", 1, &kMParams_69[3]},
    {"aeslSplit", "list text", 2, &kMParams_69[4]},
    {"aeslJoin", "text", 2, &kMParams_69[6]},
    {"aeslReplace", "text", 3, &kMParams_69[8]},
    {"hash32", "number", 1, &kMParams_69[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_70[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_70[] = {
    {"pbkdLen", "number", 1, &kMParams_70[0]},
    {"pbkdUpper", "text", 1, &kMParams_70[1]},
    {"pbkdLower", "text", 1, &kMParams_70[2]},
    {"pbkdTrim", "text", 1, &kMParams_70[3]},
    {"pbkdSplit", "list text", 2, &kMParams_70[4]},
    {"pbkdJoin", "text", 2, &kMParams_70[6]},
    {"pbkdReplace", "text", 3, &kMParams_70[8]},
    {"hash32", "number", 1, &kMParams_70[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_71[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_71[] = {
    {"scryLen", "number", 1, &kMParams_71[0]},
    {"scryUpper", "text", 1, &kMParams_71[1]},
    {"scryLower", "text", 1, &kMParams_71[2]},
    {"scryTrim", "text", 1, &kMParams_71[3]},
    {"scrySplit", "list text", 2, &kMParams_71[4]},
    {"scryJoin", "text", 2, &kMParams_71[6]},
    {"scryReplace", "text", 3, &kMParams_71[8]},
    {"hash32", "number", 1, &kMParams_71[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_72[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_72[] = {
    {"noncLen", "number", 1, &kMParams_72[0]},
    {"noncUpper", "text", 1, &kMParams_72[1]},
    {"noncLower", "text", 1, &kMParams_72[2]},
    {"noncTrim", "text", 1, &kMParams_72[3]},
    {"noncSplit", "list text", 2, &kMParams_72[4]},
    {"noncJoin", "text", 2, &kMParams_72[6]},
    {"noncReplace", "text", 3, &kMParams_72[8]},
    {"hash32", "number", 1, &kMParams_72[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_73[] = {
    {"s", "text"},
    {"data", "list number"},
    {"s", "text"},
    {"expected", "number"},
    {"crc", "number"},
    {"byte", "number"},
    {"crc", "number"},
    {"s", "text"},
    {"chunkSize", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_73[] = {
    {"crc32", "number", 1, &kMParams_73[0]},
    {"crc32List", "list number", 1, &kMParams_73[1]},
    {"verify", "bool", 2, &kMParams_73[2]},
    {"update", "number", 2, &kMParams_73[4]},
    {"finalize", "number", 1, &kMParams_73[6]},
    {"chunkCrc", "list number", 2, &kMParams_73[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_74[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_74[] = {
    {"pariLen", "number", 1, &kMParams_74[0]},
    {"pariUpper", "text", 1, &kMParams_74[1]},
    {"pariLower", "text", 1, &kMParams_74[2]},
    {"pariTrim", "text", 1, &kMParams_74[3]},
    {"pariSplit", "list text", 2, &kMParams_74[4]},
    {"pariJoin", "text", 2, &kMParams_74[6]},
    {"pariReplace", "text", 3, &kMParams_74[8]},
    {"hash32", "number", 1, &kMParams_74[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_75[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_75[] = {
    {"rleEncode", "list number", 1, &kMParams_75[0]},
    {"rleDecode", "list number", 1, &kMParams_75[1]},
    {"rleRatio", "number", 1, &kMParams_75[2]},
    {"runLength", "number", 1, &kMParams_75[3]},
    {"compress", "list number", 1, &kMParams_75[4]},
    {"decompress", "list number", 1, &kMParams_75[5]},
    {"isCompressible", "bool", 1, &kMParams_75[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_76[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_76[] = {
    {"deltaEncode", "list number", 1, &kMParams_76[0]},
    {"deltaDecode", "list number", 1, &kMParams_76[1]},
    {"deltaSum", "number", 1, &kMParams_76[2]},
    {"secondOrder", "list number", 1, &kMParams_76[3]},
    {"roundTrip", "bool", 1, &kMParams_76[4]},
    {"maxDelta", "number", 1, &kMParams_76[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_77[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_77[] = {
    {"resshuffEncode", "list number", 1, &kMParams_77[0]},
    {"resshuffDecode", "list number", 1, &kMParams_77[1]},
    {"resshuffRatio", "number", 1, &kMParams_77[2]},
    {"resshuffSize", "number", 1, &kMParams_77[3]},
    {"resshuffCompressed", "number", 1, &kMParams_77[4]},
    {"resshuffRoundTrip", "bool", 1, &kMParams_77[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_78[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_78[] = {
    {"lz77Encode", "list number", 1, &kMParams_78[0]},
    {"lz77Decode", "list number", 1, &kMParams_78[1]},
    {"lz77Ratio", "number", 1, &kMParams_78[2]},
    {"lz77Size", "number", 1, &kMParams_78[3]},
    {"lz77Compressed", "number", 1, &kMParams_78[4]},
    {"lz77RoundTrip", "bool", 1, &kMParams_78[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_79[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_79[] = {
    {"lzwEncode", "list number", 1, &kMParams_79[0]},
    {"lzwDecode", "list number", 1, &kMParams_79[1]},
    {"lzwRatio", "number", 1, &kMParams_79[2]},
    {"lzwSize", "number", 1, &kMParams_79[3]},
    {"lzwCompressed", "number", 1, &kMParams_79[4]},
    {"lzwRoundTrip", "bool", 1, &kMParams_79[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_80[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_80[] = {
    {"runlenEncode", "list number", 1, &kMParams_80[0]},
    {"runlenDecode", "list number", 1, &kMParams_80[1]},
    {"runlenRatio", "number", 1, &kMParams_80[2]},
    {"runlenSize", "number", 1, &kMParams_80[3]},
    {"runlenCompressed", "number", 1, &kMParams_80[4]},
    {"runlenRoundTrip", "bool", 1, &kMParams_80[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_81[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_81[] = {
    {"bitpackEncode", "list number", 1, &kMParams_81[0]},
    {"bitpackDecode", "list number", 1, &kMParams_81[1]},
    {"bitpackRatio", "number", 1, &kMParams_81[2]},
    {"bitpackSize", "number", 1, &kMParams_81[3]},
    {"bitpackCompressed", "number", 1, &kMParams_81[4]},
    {"bitpackRoundTrip", "bool", 1, &kMParams_81[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_82[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_82[] = {
    {"varintEncode", "list number", 1, &kMParams_82[0]},
    {"varintDecode", "list number", 1, &kMParams_82[1]},
    {"varintRatio", "number", 1, &kMParams_82[2]},
    {"varintSize", "number", 1, &kMParams_82[3]},
    {"varintCompressed", "number", 1, &kMParams_82[4]},
    {"varintRoundTrip", "bool", 1, &kMParams_82[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_83[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_83[] = {
    {"dictEncode", "list number", 1, &kMParams_83[0]},
    {"dictDecode", "list number", 1, &kMParams_83[1]},
    {"dictRatio", "number", 1, &kMParams_83[2]},
    {"dictSize", "number", 1, &kMParams_83[3]},
    {"dictCompressed", "number", 1, &kMParams_83[4]},
    {"dictRoundTrip", "bool", 1, &kMParams_83[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_84[] = {
    {"data", "list number"},
    {"encoded", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {"data", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_84[] = {
    {"frameEncode", "list number", 1, &kMParams_84[0]},
    {"frameDecode", "list number", 1, &kMParams_84[1]},
    {"frameRatio", "number", 1, &kMParams_84[2]},
    {"frameSize", "number", 1, &kMParams_84[3]},
    {"frameCompressed", "number", 1, &kMParams_84[4]},
    {"frameRoundTrip", "bool", 1, &kMParams_84[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_85[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_85[] = {
    {"jsonLen", "number", 1, &kMParams_85[0]},
    {"jsonUpper", "text", 1, &kMParams_85[1]},
    {"jsonLower", "text", 1, &kMParams_85[2]},
    {"jsonTrim", "text", 1, &kMParams_85[3]},
    {"jsonSplit", "list text", 2, &kMParams_85[4]},
    {"jsonJoin", "text", 2, &kMParams_85[6]},
    {"jsonReplace", "text", 3, &kMParams_85[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_86[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_86[] = {
    {"xmlLen", "number", 1, &kMParams_86[0]},
    {"xmlUpper", "text", 1, &kMParams_86[1]},
    {"xmlLower", "text", 1, &kMParams_86[2]},
    {"xmlTrim", "text", 1, &kMParams_86[3]},
    {"xmlSplit", "list text", 2, &kMParams_86[4]},
    {"xmlJoin", "text", 2, &kMParams_86[6]},
    {"xmlReplace", "text", 3, &kMParams_86[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_87[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_87[] = {
    {"iniLen", "number", 1, &kMParams_87[0]},
    {"iniUpper", "text", 1, &kMParams_87[1]},
    {"iniLower", "text", 1, &kMParams_87[2]},
    {"iniTrim", "text", 1, &kMParams_87[3]},
    {"iniSplit", "list text", 2, &kMParams_87[4]},
    {"iniJoin", "text", 2, &kMParams_87[6]},
    {"iniReplace", "text", 3, &kMParams_87[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_88[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_88[] = {
    {"tomlLen", "number", 1, &kMParams_88[0]},
    {"tomlUpper", "text", 1, &kMParams_88[1]},
    {"tomlLower", "text", 1, &kMParams_88[2]},
    {"tomlTrim", "text", 1, &kMParams_88[3]},
    {"tomlSplit", "list text", 2, &kMParams_88[4]},
    {"tomlJoin", "text", 2, &kMParams_88[6]},
    {"tomlReplace", "text", 3, &kMParams_88[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_89[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_89[] = {
    {"pathLen", "number", 1, &kMParams_89[0]},
    {"pathUpper", "text", 1, &kMParams_89[1]},
    {"pathLower", "text", 1, &kMParams_89[2]},
    {"pathTrim", "text", 1, &kMParams_89[3]},
    {"pathSplit", "list text", 2, &kMParams_89[4]},
    {"pathJoin", "text", 2, &kMParams_89[6]},
    {"pathReplace", "text", 3, &kMParams_89[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_90[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_90[] = {
    {"yamlLen", "number", 1, &kMParams_90[0]},
    {"yamlUpper", "text", 1, &kMParams_90[1]},
    {"yamlLower", "text", 1, &kMParams_90[2]},
    {"yamlTrim", "text", 1, &kMParams_90[3]},
    {"yamlSplit", "list text", 2, &kMParams_90[4]},
    {"yamlJoin", "text", 2, &kMParams_90[6]},
    {"yamlReplace", "text", 3, &kMParams_90[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_91[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"line", "text"},
    {"delim", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_91[] = {
    {"csvLen", "number", 1, &kMParams_91[0]},
    {"csvUpper", "text", 1, &kMParams_91[1]},
    {"csvLower", "text", 1, &kMParams_91[2]},
    {"csvTrim", "text", 1, &kMParams_91[3]},
    {"csvSplit", "list text", 2, &kMParams_91[4]},
    {"csvJoin", "text", 2, &kMParams_91[6]},
    {"csvReplace", "text", 3, &kMParams_91[8]},
    {"parseRow", "list text", 2, &kMParams_91[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_92[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_92[] = {
    {"htmlLen", "number", 1, &kMParams_92[0]},
    {"htmlUpper", "text", 1, &kMParams_92[1]},
    {"htmlLower", "text", 1, &kMParams_92[2]},
    {"htmlTrim", "text", 1, &kMParams_92[3]},
    {"htmlSplit", "list text", 2, &kMParams_92[4]},
    {"htmlJoin", "text", 2, &kMParams_92[6]},
    {"htmlReplace", "text", 3, &kMParams_92[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_93[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_93[] = {
    {"logLen", "number", 1, &kMParams_93[0]},
    {"logUpper", "text", 1, &kMParams_93[1]},
    {"logLower", "text", 1, &kMParams_93[2]},
    {"logTrim", "text", 1, &kMParams_93[3]},
    {"logSplit", "list text", 2, &kMParams_93[4]},
    {"logJoin", "text", 2, &kMParams_93[6]},
    {"logReplace", "text", 3, &kMParams_93[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_94[] = {
    {"uri", "text"},
    {"uri", "text"},
    {"uri", "text"},
    {"uri", "text"},
    {"uri", "text"},
    {"uri", "text"},
    {"uri", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_94[] = {
    {"scheme", "text", 1, &kMParams_94[0]},
    {"host", "text", 1, &kMParams_94[1]},
    {"path", "text", 1, &kMParams_94[2]},
    {"query", "text", 1, &kMParams_94[3]},
    {"fragment", "text", 1, &kMParams_94[4]},
    {"port", "number", 1, &kMParams_94[5]},
    {"isValid", "bool", 1, &kMParams_94[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_95[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_95[] = {
    {"mimeLen", "number", 1, &kMParams_95[0]},
    {"mimeUpper", "text", 1, &kMParams_95[1]},
    {"mimeLower", "text", 1, &kMParams_95[2]},
    {"mimeTrim", "text", 1, &kMParams_95[3]},
    {"mimeSplit", "list text", 2, &kMParams_95[4]},
    {"mimeJoin", "text", 2, &kMParams_95[6]},
    {"mimeReplace", "text", 3, &kMParams_95[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_96[] = {
    {"hex", "text"},
    {"bytes", "list number"},
    {"hex", "text"},
    {"hex", "text"},
    {"s", "text"},
    {"bytes", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_96[] = {
    {"decode", "list number", 1, &kMParams_96[0]},
    {"encode", "text", 1, &kMParams_96[1]},
    {"nibbleCount", "number", 1, &kMParams_96[2]},
    {"byteCount", "number", 1, &kMParams_96[3]},
    {"isHex", "bool", 1, &kMParams_96[4]},
    {"roundTrip", "bool", 1, &kMParams_96[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_97[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_97[] = {
    {"binaLen", "number", 1, &kMParams_97[0]},
    {"binaUpper", "text", 1, &kMParams_97[1]},
    {"binaLower", "text", 1, &kMParams_97[2]},
    {"binaTrim", "text", 1, &kMParams_97[3]},
    {"binaSplit", "list text", 2, &kMParams_97[4]},
    {"binaJoin", "text", 2, &kMParams_97[6]},
    {"binaReplace", "text", 3, &kMParams_97[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_98[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_98[] = {
    {"tempLen", "number", 1, &kMParams_98[0]},
    {"tempUpper", "text", 1, &kMParams_98[1]},
    {"tempLower", "text", 1, &kMParams_98[2]},
    {"tempTrim", "text", 1, &kMParams_98[3]},
    {"tempSplit", "list text", 2, &kMParams_98[4]},
    {"tempJoin", "text", 2, &kMParams_98[6]},
    {"tempReplace", "text", 3, &kMParams_98[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_99[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_99[] = {
    {"exprLen", "number", 1, &kMParams_99[0]},
    {"exprUpper", "text", 1, &kMParams_99[1]},
    {"exprLower", "text", 1, &kMParams_99[2]},
    {"exprTrim", "text", 1, &kMParams_99[3]},
    {"exprSplit", "list text", 2, &kMParams_99[4]},
    {"exprJoin", "text", 2, &kMParams_99[6]},
    {"exprReplace", "text", 3, &kMParams_99[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_100[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_100[] = {
    {"filtSum", "number", 1, &kMParams_100[0]},
    {"filtMean", "number", 1, &kMParams_100[1]},
    {"filtMin", "number", 1, &kMParams_100[2]},
    {"filtMax", "number", 1, &kMParams_100[3]},
    {"filtVar", "number", 1, &kMParams_100[4]},
    {"filtStd", "number", 1, &kMParams_100[5]},
    {"filtNorm", "list number", 1, &kMParams_100[6]},
    {"filterGt", "list number", 2, &kMParams_100[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_101[] = {
    {"values", "list number"},
    {"keys", "list number"},
    {"keys", "list number"},
    {"values", "list number"},
    {"keys", "list number"},
    {"keys", "list number"},
    {"values", "list number"},
    {"keys", "list number"},
    {"keys", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_101[] = {
    {"groupSum", "list number", 2, &kMParams_101[0]},
    {"groupCount", "list number", 1, &kMParams_101[2]},
    {"groupMean", "list number", 2, &kMParams_101[3]},
    {"uniqueKeys", "list number", 1, &kMParams_101[5]},
    {"groupMax", "list number", 2, &kMParams_101[6]},
    {"numGroups", "number", 1, &kMParams_101[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_102[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_102[] = {
    {"aggrSum", "number", 1, &kMParams_102[0]},
    {"aggrMean", "number", 1, &kMParams_102[1]},
    {"aggrMin", "number", 1, &kMParams_102[2]},
    {"aggrMax", "number", 1, &kMParams_102[3]},
    {"aggrVar", "number", 1, &kMParams_102[4]},
    {"aggrStd", "number", 1, &kMParams_102[5]},
    {"aggrNorm", "list number", 1, &kMParams_102[6]},
    {"filterGt", "list number", 2, &kMParams_102[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_103[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_103[] = {
    {"joinSum", "number", 1, &kMParams_103[0]},
    {"joinMean", "number", 1, &kMParams_103[1]},
    {"joinMin", "number", 1, &kMParams_103[2]},
    {"joinMax", "number", 1, &kMParams_103[3]},
    {"joinVar", "number", 1, &kMParams_103[4]},
    {"joinStd", "number", 1, &kMParams_103[5]},
    {"joinNorm", "list number", 1, &kMParams_103[6]},
    {"filterGt", "list number", 2, &kMParams_103[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_104[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_104[] = {
    {"pivoSum", "number", 1, &kMParams_104[0]},
    {"pivoMean", "number", 1, &kMParams_104[1]},
    {"pivoMin", "number", 1, &kMParams_104[2]},
    {"pivoMax", "number", 1, &kMParams_104[3]},
    {"pivoVar", "number", 1, &kMParams_104[4]},
    {"pivoStd", "number", 1, &kMParams_104[5]},
    {"pivoNorm", "list number", 1, &kMParams_104[6]},
    {"filterGt", "list number", 2, &kMParams_104[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_105[] = {
    {"col", "list number"},
    {"col", "list number"},
    {"col", "list number"},
    {"col", "list number"},
    {"col", "list number"},
    {"k", "number"},
    {"col", "list number"},
    {"k", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_105[] = {
    {"sortAsc", "list number", 1, &kMParams_105[0]},
    {"sortDesc", "list number", 1, &kMParams_105[1]},
    {"argsort", "list number", 1, &kMParams_105[2]},
    {"rank", "list number", 1, &kMParams_105[3]},
    {"topK", "list number", 2, &kMParams_105[4]},
    {"bottomK", "list number", 2, &kMParams_105[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_106[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_106[] = {
    {"seleSum", "number", 1, &kMParams_106[0]},
    {"seleMean", "number", 1, &kMParams_106[1]},
    {"seleMin", "number", 1, &kMParams_106[2]},
    {"seleMax", "number", 1, &kMParams_106[3]},
    {"seleVar", "number", 1, &kMParams_106[4]},
    {"seleStd", "number", 1, &kMParams_106[5]},
    {"seleNorm", "list number", 1, &kMParams_106[6]},
    {"filterGt", "list number", 2, &kMParams_106[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_107[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_107[] = {
    {"distSum", "number", 1, &kMParams_107[0]},
    {"distMean", "number", 1, &kMParams_107[1]},
    {"distMin", "number", 1, &kMParams_107[2]},
    {"distMax", "number", 1, &kMParams_107[3]},
    {"distVar", "number", 1, &kMParams_107[4]},
    {"distStd", "number", 1, &kMParams_107[5]},
    {"distNorm", "list number", 1, &kMParams_107[6]},
    {"filterGt", "list number", 2, &kMParams_107[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_108[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_108[] = {
    {"limiSum", "number", 1, &kMParams_108[0]},
    {"limiMean", "number", 1, &kMParams_108[1]},
    {"limiMin", "number", 1, &kMParams_108[2]},
    {"limiMax", "number", 1, &kMParams_108[3]},
    {"limiVar", "number", 1, &kMParams_108[4]},
    {"limiStd", "number", 1, &kMParams_108[5]},
    {"limiNorm", "list number", 1, &kMParams_108[6]},
    {"filterGt", "list number", 2, &kMParams_108[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_109[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_109[] = {
    {"haviSum", "number", 1, &kMParams_109[0]},
    {"haviMean", "number", 1, &kMParams_109[1]},
    {"haviMin", "number", 1, &kMParams_109[2]},
    {"haviMax", "number", 1, &kMParams_109[3]},
    {"haviVar", "number", 1, &kMParams_109[4]},
    {"haviStd", "number", 1, &kMParams_109[5]},
    {"haviNorm", "list number", 1, &kMParams_109[6]},
    {"filterGt", "list number", 2, &kMParams_109[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_110[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_110[] = {
    {"unioSum", "number", 1, &kMParams_110[0]},
    {"unioMean", "number", 1, &kMParams_110[1]},
    {"unioMin", "number", 1, &kMParams_110[2]},
    {"unioMax", "number", 1, &kMParams_110[3]},
    {"unioVar", "number", 1, &kMParams_110[4]},
    {"unioStd", "number", 1, &kMParams_110[5]},
    {"unioNorm", "list number", 1, &kMParams_110[6]},
    {"filterGt", "list number", 2, &kMParams_110[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_111[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_111[] = {
    {"windSum", "number", 1, &kMParams_111[0]},
    {"windMean", "number", 1, &kMParams_111[1]},
    {"windMin", "number", 1, &kMParams_111[2]},
    {"windMax", "number", 1, &kMParams_111[3]},
    {"windVar", "number", 1, &kMParams_111[4]},
    {"windStd", "number", 1, &kMParams_111[5]},
    {"windNorm", "list number", 1, &kMParams_111[6]},
    {"filterGt", "list number", 2, &kMParams_111[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_112[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_112[] = {
    {"normSum", "number", 1, &kMParams_112[0]},
    {"normMean", "number", 1, &kMParams_112[1]},
    {"normMin", "number", 1, &kMParams_112[2]},
    {"normMax", "number", 1, &kMParams_112[3]},
    {"normVar", "number", 1, &kMParams_112[4]},
    {"normStd", "number", 1, &kMParams_112[5]},
    {"normNorm", "list number", 1, &kMParams_112[6]},
    {"filterGt", "list number", 2, &kMParams_112[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_113[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_113[] = {
    {"rollSum", "number", 1, &kMParams_113[0]},
    {"rollMean", "number", 1, &kMParams_113[1]},
    {"rollMin", "number", 1, &kMParams_113[2]},
    {"rollMax", "number", 1, &kMParams_113[3]},
    {"rollVar", "number", 1, &kMParams_113[4]},
    {"rollStd", "number", 1, &kMParams_113[5]},
    {"rollNorm", "list number", 1, &kMParams_113[6]},
    {"filterGt", "list number", 2, &kMParams_113[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_114[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"col", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_114[] = {
    {"sampSum", "number", 1, &kMParams_114[0]},
    {"sampMean", "number", 1, &kMParams_114[1]},
    {"sampMin", "number", 1, &kMParams_114[2]},
    {"sampMax", "number", 1, &kMParams_114[3]},
    {"sampVar", "number", 1, &kMParams_114[4]},
    {"sampStd", "number", 1, &kMParams_114[5]},
    {"sampNorm", "list number", 1, &kMParams_114[6]},
    {"filterGt", "list number", 2, &kMParams_114[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_115[] = {
    {"samples", "number"},
    {"seed", "number"},
    {"samples", "number"},
    {"seed", "number"},
    {"a", "number"},
    {"b", "number"},
    {"n", "number"},
    {"seed", "number"},
    {"samples", "list number"},
    {"data", "list number"},
    {"samples", "number"},
    {"seed", "number"},
    {"samples", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_115[] = {
    {"estimatePi", "number", 2, &kMParams_115[0]},
    {"integrate", "number", 4, &kMParams_115[2]},
    {"randomNormal", "list number", 2, &kMParams_115[6]},
    {"confidence95", "list number", 1, &kMParams_115[8]},
    {"bootstrapMean", "number", 3, &kMParams_115[9]},
    {"varianceReduction", "number", 2, &kMParams_115[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_116[] = {
    {"trans", "list number"},
    {"states", "number"},
    {"trans", "list number"},
    {"states", "number"},
    {"steps", "number"},
    {"seed", "number"},
    {"trans", "list number"},
    {"states", "number"},
    {"from", "number"},
    {"to", "number"},
    {"trans", "list number"},
    {"states", "number"},
    {"target", "number"},
    {"trans", "list number"},
    {"states", "number"},
    {"trans", "list number"},
    {"states", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_116[] = {
    {"steadyState", "list number", 2, &kMParams_116[0]},
    {"simulate", "list number", 4, &kMParams_116[2]},
    {"transitionProb", "number", 4, &kMParams_116[6]},
    {"expectedSteps", "number", 3, &kMParams_116[10]},
    {"isStochastic", "bool", 2, &kMParams_116[13]},
    {"mixingTime", "number", 2, &kMParams_116[15]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_117[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_117[] = {
    {"randSum", "number", 1, &kMParams_117[0]},
    {"randMean", "number", 1, &kMParams_117[1]},
    {"randMin", "number", 1, &kMParams_117[2]},
    {"randMax", "number", 1, &kMParams_117[3]},
    {"randVar", "number", 1, &kMParams_117[4]},
    {"randStd", "number", 1, &kMParams_117[5]},
    {"randNorm", "list number", 1, &kMParams_117[6]},
    {"simulate", "list number", 2, &kMParams_117[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_118[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_118[] = {
    {"browSum", "number", 1, &kMParams_118[0]},
    {"browMean", "number", 1, &kMParams_118[1]},
    {"browMin", "number", 1, &kMParams_118[2]},
    {"browMax", "number", 1, &kMParams_118[3]},
    {"browVar", "number", 1, &kMParams_118[4]},
    {"browStd", "number", 1, &kMParams_118[5]},
    {"browNorm", "list number", 1, &kMParams_118[6]},
    {"simulate", "list number", 2, &kMParams_118[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_119[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_119[] = {
    {"poisSum", "number", 1, &kMParams_119[0]},
    {"poisMean", "number", 1, &kMParams_119[1]},
    {"poisMin", "number", 1, &kMParams_119[2]},
    {"poisMax", "number", 1, &kMParams_119[3]},
    {"poisVar", "number", 1, &kMParams_119[4]},
    {"poisStd", "number", 1, &kMParams_119[5]},
    {"poisNorm", "list number", 1, &kMParams_119[6]},
    {"simulate", "list number", 2, &kMParams_119[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_120[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_120[] = {
    {"queuSum", "number", 1, &kMParams_120[0]},
    {"queuMean", "number", 1, &kMParams_120[1]},
    {"queuMin", "number", 1, &kMParams_120[2]},
    {"queuMax", "number", 1, &kMParams_120[3]},
    {"queuVar", "number", 1, &kMParams_120[4]},
    {"queuStd", "number", 1, &kMParams_120[5]},
    {"queuNorm", "list number", 1, &kMParams_120[6]},
    {"simulate", "list number", 2, &kMParams_120[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_121[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_121[] = {
    {"inveSum", "number", 1, &kMParams_121[0]},
    {"inveMean", "number", 1, &kMParams_121[1]},
    {"inveMin", "number", 1, &kMParams_121[2]},
    {"inveMax", "number", 1, &kMParams_121[3]},
    {"inveVar", "number", 1, &kMParams_121[4]},
    {"inveStd", "number", 1, &kMParams_121[5]},
    {"inveNorm", "list number", 1, &kMParams_121[6]},
    {"simulate", "list number", 2, &kMParams_121[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_122[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_122[] = {
    {"discSum", "number", 1, &kMParams_122[0]},
    {"discMean", "number", 1, &kMParams_122[1]},
    {"discMin", "number", 1, &kMParams_122[2]},
    {"discMax", "number", 1, &kMParams_122[3]},
    {"discVar", "number", 1, &kMParams_122[4]},
    {"discStd", "number", 1, &kMParams_122[5]},
    {"discNorm", "list number", 1, &kMParams_122[6]},
    {"simulate", "list number", 2, &kMParams_122[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_123[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_123[] = {
    {"loreSum", "number", 1, &kMParams_123[0]},
    {"loreMean", "number", 1, &kMParams_123[1]},
    {"loreMin", "number", 1, &kMParams_123[2]},
    {"loreMax", "number", 1, &kMParams_123[3]},
    {"loreVar", "number", 1, &kMParams_123[4]},
    {"loreStd", "number", 1, &kMParams_123[5]},
    {"loreNorm", "list number", 1, &kMParams_123[6]},
    {"simulate", "list number", 2, &kMParams_123[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_124[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"steps", "number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_124[] = {
    {"birtSum", "number", 1, &kMParams_124[0]},
    {"birtMean", "number", 1, &kMParams_124[1]},
    {"birtMin", "number", 1, &kMParams_124[2]},
    {"birtMax", "number", 1, &kMParams_124[3]},
    {"birtVar", "number", 1, &kMParams_124[4]},
    {"birtStd", "number", 1, &kMParams_124[5]},
    {"birtNorm", "list number", 1, &kMParams_124[6]},
    {"simulate", "list number", 2, &kMParams_124[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_125[] = {
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {"spot", "number"},
    {"strike", "number"},
    {"rate", "number"},
    {"vol", "number"},
    {"time", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_125[] = {
    {"blackScholes", "number", 5, &kMParams_125[0]},
    {"putPrice", "number", 5, &kMParams_125[5]},
    {"intrinsic", "number", 2, &kMParams_125[10]},
    {"timeValue", "number", 5, &kMParams_125[12]},
    {"delta", "number", 5, &kMParams_125[17]},
    {"gamma", "number", 5, &kMParams_125[22]},
    {"vega", "number", 5, &kMParams_125[27]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_126[] = {
    {"face", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"coupon", "number"},
    {"price", "number"},
    {"face", "number"},
    {"coupon", "number"},
    {"years", "number"},
    {"face", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"coupon", "number"},
    {"face", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"coupon", "number"},
    {"coupon", "number"},
    {"price", "number"},
    {"coupon", "number"},
    {"days", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_126[] = {
    {"pv", "number", 4, &kMParams_126[0]},
    {"ytm", "number", 4, &kMParams_126[4]},
    {"duration", "number", 4, &kMParams_126[8]},
    {"convexity", "number", 4, &kMParams_126[12]},
    {"couponYield", "number", 2, &kMParams_126[16]},
    {"accruedInterest", "number", 2, &kMParams_126[18]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_127[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_127[] = {
    {"portSum", "number", 1, &kMParams_127[0]},
    {"portMean", "number", 1, &kMParams_127[1]},
    {"portMin", "number", 1, &kMParams_127[2]},
    {"portMax", "number", 1, &kMParams_127[3]},
    {"portVar", "number", 1, &kMParams_127[4]},
    {"portStd", "number", 1, &kMParams_127[5]},
    {"portNorm", "list number", 1, &kMParams_127[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_128[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_128[] = {
    {"blacSum", "number", 1, &kMParams_128[0]},
    {"blacMean", "number", 1, &kMParams_128[1]},
    {"blacMin", "number", 1, &kMParams_128[2]},
    {"blacMax", "number", 1, &kMParams_128[3]},
    {"blacVar", "number", 1, &kMParams_128[4]},
    {"blacStd", "number", 1, &kMParams_128[5]},
    {"blacNorm", "list number", 1, &kMParams_128[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_129[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_129[] = {
    {"greeSum", "number", 1, &kMParams_129[0]},
    {"greeMean", "number", 1, &kMParams_129[1]},
    {"greeMin", "number", 1, &kMParams_129[2]},
    {"greeMax", "number", 1, &kMParams_129[3]},
    {"greeVar", "number", 1, &kMParams_129[4]},
    {"greeStd", "number", 1, &kMParams_129[5]},
    {"greeNorm", "list number", 1, &kMParams_129[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_130[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_130[] = {
    {"yielSum", "number", 1, &kMParams_130[0]},
    {"yielMean", "number", 1, &kMParams_130[1]},
    {"yielMin", "number", 1, &kMParams_130[2]},
    {"yielMax", "number", 1, &kMParams_130[3]},
    {"yielVar", "number", 1, &kMParams_130[4]},
    {"yielStd", "number", 1, &kMParams_130[5]},
    {"yielNorm", "list number", 1, &kMParams_130[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_131[] = {
    {"returns", "list number"},
    {"rf", "number"},
    {"returns", "list number"},
    {"rf", "number"},
    {"prices", "list number"},
    {"returns", "list number"},
    {"prices", "list number"},
    {"returns", "list number"},
    {"returns", "list number"},
    {"periods", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_131[] = {
    {"sharpe", "number", 2, &kMParams_131[0]},
    {"sortino", "number", 2, &kMParams_131[2]},
    {"maxDrawdown", "number", 1, &kMParams_131[4]},
    {"calmar", "number", 2, &kMParams_131[5]},
    {"volatility", "number", 1, &kMParams_131[7]},
    {"annualizedReturn", "number", 2, &kMParams_131[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_132[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_132[] = {
    {"varSum", "number", 1, &kMParams_132[0]},
    {"varMean", "number", 1, &kMParams_132[1]},
    {"varMin", "number", 1, &kMParams_132[2]},
    {"varMax", "number", 1, &kMParams_132[3]},
    {"varVar", "number", 1, &kMParams_132[4]},
    {"varStd", "number", 1, &kMParams_132[5]},
    {"varNorm", "list number", 1, &kMParams_132[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_133[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_133[] = {
    {"foreSum", "number", 1, &kMParams_133[0]},
    {"foreMean", "number", 1, &kMParams_133[1]},
    {"foreMin", "number", 1, &kMParams_133[2]},
    {"foreMax", "number", 1, &kMParams_133[3]},
    {"foreVar", "number", 1, &kMParams_133[4]},
    {"foreStd", "number", 1, &kMParams_133[5]},
    {"foreNorm", "list number", 1, &kMParams_133[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_134[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_134[] = {
    {"amorSum", "number", 1, &kMParams_134[0]},
    {"amorMean", "number", 1, &kMParams_134[1]},
    {"amorMin", "number", 1, &kMParams_134[2]},
    {"amorMax", "number", 1, &kMParams_134[3]},
    {"amorVar", "number", 1, &kMParams_134[4]},
    {"amorStd", "number", 1, &kMParams_134[5]},
    {"amorNorm", "list number", 1, &kMParams_134[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_135[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_135[] = {
    {"futuSum", "number", 1, &kMParams_135[0]},
    {"futuMean", "number", 1, &kMParams_135[1]},
    {"futuMin", "number", 1, &kMParams_135[2]},
    {"futuMax", "number", 1, &kMParams_135[3]},
    {"futuVar", "number", 1, &kMParams_135[4]},
    {"futuStd", "number", 1, &kMParams_135[5]},
    {"futuNorm", "list number", 1, &kMParams_135[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_136[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_136[] = {
    {"swapSum", "number", 1, &kMParams_136[0]},
    {"swapMean", "number", 1, &kMParams_136[1]},
    {"swapMin", "number", 1, &kMParams_136[2]},
    {"swapMax", "number", 1, &kMParams_136[3]},
    {"swapVar", "number", 1, &kMParams_136[4]},
    {"swapStd", "number", 1, &kMParams_136[5]},
    {"swapNorm", "list number", 1, &kMParams_136[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_137[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_137[] = {
    {"riskSum", "number", 1, &kMParams_137[0]},
    {"riskMean", "number", 1, &kMParams_137[1]},
    {"riskMin", "number", 1, &kMParams_137[2]},
    {"riskMax", "number", 1, &kMParams_137[3]},
    {"riskVar", "number", 1, &kMParams_137[4]},
    {"riskStd", "number", 1, &kMParams_137[5]},
    {"riskNorm", "list number", 1, &kMParams_137[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_138[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_138[] = {
    {"hedgSum", "number", 1, &kMParams_138[0]},
    {"hedgMean", "number", 1, &kMParams_138[1]},
    {"hedgMin", "number", 1, &kMParams_138[2]},
    {"hedgMax", "number", 1, &kMParams_138[3]},
    {"hedgVar", "number", 1, &kMParams_138[4]},
    {"hedgStd", "number", 1, &kMParams_138[5]},
    {"hedgNorm", "list number", 1, &kMParams_138[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_139[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_139[] = {
    {"diviSum", "number", 1, &kMParams_139[0]},
    {"diviMean", "number", 1, &kMParams_139[1]},
    {"diviMin", "number", 1, &kMParams_139[2]},
    {"diviMax", "number", 1, &kMParams_139[3]},
    {"diviVar", "number", 1, &kMParams_139[4]},
    {"diviStd", "number", 1, &kMParams_139[5]},
    {"diviNorm", "list number", 1, &kMParams_139[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_140[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"v", "list number"},
    {"win", "number"},
    {"signal", "list number"},
    {"kernel", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_140[] = {
    {"convolve", "list number", 2, &kMParams_140[0]},
    {"crossCorr", "list number", 2, &kMParams_140[2]},
    {"movingAvg", "list number", 2, &kMParams_140[4]},
    {"deconvSimple", "list number", 2, &kMParams_140[6]},
    {"energy", "number", 1, &kMParams_140[8]},
    {"normalize", "list number", 1, &kMParams_140[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_141[] = {
    {"signal", "list number"},
    {"signal", "list number"},
    {"signal", "list number"},
    {"signal", "list number"},
    {"spectrum", "list number"},
    {"n", "number"},
    {"signal", "list number"},
    {"lo", "number"},
    {"hi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_141[] = {
    {"dft", "list number", 1, &kMParams_141[0]},
    {"magnitude", "list number", 1, &kMParams_141[1]},
    {"powerSpectrum", "list number", 1, &kMParams_141[2]},
    {"dominantFreq", "number", 1, &kMParams_141[3]},
    {"inverseDft", "list number", 2, &kMParams_141[4]},
    {"bandEnergy", "number", 3, &kMParams_141[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_142[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_142[] = {
    {"polySum", "number", 1, &kMParams_142[0]},
    {"polyMean", "number", 1, &kMParams_142[1]},
    {"polyMin", "number", 1, &kMParams_142[2]},
    {"polyMax", "number", 1, &kMParams_142[3]},
    {"polyVar", "number", 1, &kMParams_142[4]},
    {"polyStd", "number", 1, &kMParams_142[5]},
    {"polyNorm", "list number", 1, &kMParams_142[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_143[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_143[] = {
    {"eigeSum", "number", 1, &kMParams_143[0]},
    {"eigeMean", "number", 1, &kMParams_143[1]},
    {"eigeMin", "number", 1, &kMParams_143[2]},
    {"eigeMax", "number", 1, &kMParams_143[3]},
    {"eigeVar", "number", 1, &kMParams_143[4]},
    {"eigeStd", "number", 1, &kMParams_143[5]},
    {"eigeNorm", "list number", 1, &kMParams_143[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_144[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_144[] = {
    {"matrSum", "number", 1, &kMParams_144[0]},
    {"matrMean", "number", 1, &kMParams_144[1]},
    {"matrMin", "number", 1, &kMParams_144[2]},
    {"matrMax", "number", 1, &kMParams_144[3]},
    {"matrVar", "number", 1, &kMParams_144[4]},
    {"matrStd", "number", 1, &kMParams_144[5]},
    {"matrNorm", "list number", 1, &kMParams_144[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_145[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_145[] = {
    {"inteSum", "number", 1, &kMParams_145[0]},
    {"inteMean", "number", 1, &kMParams_145[1]},
    {"inteMin", "number", 1, &kMParams_145[2]},
    {"inteMax", "number", 1, &kMParams_145[3]},
    {"inteVar", "number", 1, &kMParams_145[4]},
    {"inteStd", "number", 1, &kMParams_145[5]},
    {"inteNorm", "list number", 1, &kMParams_145[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_146[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_146[] = {
    {"deriSum", "number", 1, &kMParams_146[0]},
    {"deriMean", "number", 1, &kMParams_146[1]},
    {"deriMin", "number", 1, &kMParams_146[2]},
    {"deriMax", "number", 1, &kMParams_146[3]},
    {"deriVar", "number", 1, &kMParams_146[4]},
    {"deriStd", "number", 1, &kMParams_146[5]},
    {"deriNorm", "list number", 1, &kMParams_146[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_147[] = {
    {"v", "list number"},
    {"alpha", "number"},
    {"v", "list number"},
    {"alpha", "number"},
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"lo", "number"},
    {"hi", "number"},
    {"signal", "list number"},
    {"noise", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_147[] = {
    {"lowPass", "list number", 2, &kMParams_147[0]},
    {"highPass", "list number", 2, &kMParams_147[2]},
    {"medianFilter", "list number", 2, &kMParams_147[4]},
    {"savgol", "list number", 2, &kMParams_147[6]},
    {"bandpass", "list number", 3, &kMParams_147[8]},
    {"snr", "number", 2, &kMParams_147[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_148[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_148[] = {
    {"waveSum", "number", 1, &kMParams_148[0]},
    {"waveMean", "number", 1, &kMParams_148[1]},
    {"waveMin", "number", 1, &kMParams_148[2]},
    {"waveMax", "number", 1, &kMParams_148[3]},
    {"waveVar", "number", 1, &kMParams_148[4]},
    {"waveStd", "number", 1, &kMParams_148[5]},
    {"waveNorm", "list number", 1, &kMParams_148[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_149[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_149[] = {
    {"resaSum", "number", 1, &kMParams_149[0]},
    {"resaMean", "number", 1, &kMParams_149[1]},
    {"resaMin", "number", 1, &kMParams_149[2]},
    {"resaMax", "number", 1, &kMParams_149[3]},
    {"resaVar", "number", 1, &kMParams_149[4]},
    {"resaStd", "number", 1, &kMParams_149[5]},
    {"resaNorm", "list number", 1, &kMParams_149[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_150[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_150[] = {
    {"inteSum", "number", 1, &kMParams_150[0]},
    {"inteMean", "number", 1, &kMParams_150[1]},
    {"inteMin", "number", 1, &kMParams_150[2]},
    {"inteMax", "number", 1, &kMParams_150[3]},
    {"inteVar", "number", 1, &kMParams_150[4]},
    {"inteStd", "number", 1, &kMParams_150[5]},
    {"inteNorm", "list number", 1, &kMParams_150[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_151[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_151[] = {
    {"spliSum", "number", 1, &kMParams_151[0]},
    {"spliMean", "number", 1, &kMParams_151[1]},
    {"spliMin", "number", 1, &kMParams_151[2]},
    {"spliMax", "number", 1, &kMParams_151[3]},
    {"spliVar", "number", 1, &kMParams_151[4]},
    {"spliStd", "number", 1, &kMParams_151[5]},
    {"spliNorm", "list number", 1, &kMParams_151[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_152[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_152[] = {
    {"corrSum", "number", 1, &kMParams_152[0]},
    {"corrMean", "number", 1, &kMParams_152[1]},
    {"corrMin", "number", 1, &kMParams_152[2]},
    {"corrMax", "number", 1, &kMParams_152[3]},
    {"corrVar", "number", 1, &kMParams_152[4]},
    {"corrStd", "number", 1, &kMParams_152[5]},
    {"corrNorm", "list number", 1, &kMParams_152[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_153[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_153[] = {
    {"autoSum", "number", 1, &kMParams_153[0]},
    {"autoMean", "number", 1, &kMParams_153[1]},
    {"autoMin", "number", 1, &kMParams_153[2]},
    {"autoMax", "number", 1, &kMParams_153[3]},
    {"autoVar", "number", 1, &kMParams_153[4]},
    {"autoStd", "number", 1, &kMParams_153[5]},
    {"autoNorm", "list number", 1, &kMParams_153[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_154[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_154[] = {
    {"poweSum", "number", 1, &kMParams_154[0]},
    {"poweMean", "number", 1, &kMParams_154[1]},
    {"poweMin", "number", 1, &kMParams_154[2]},
    {"poweMax", "number", 1, &kMParams_154[3]},
    {"poweVar", "number", 1, &kMParams_154[4]},
    {"poweStd", "number", 1, &kMParams_154[5]},
    {"poweNorm", "list number", 1, &kMParams_154[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_155[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_155[] = {
    {"stemLen", "number", 1, &kMParams_155[0]},
    {"stemUpper", "text", 1, &kMParams_155[1]},
    {"stemLower", "text", 1, &kMParams_155[2]},
    {"stemTrim", "text", 1, &kMParams_155[3]},
    {"stemSplit", "list text", 2, &kMParams_155[4]},
    {"stemJoin", "text", 2, &kMParams_155[6]},
    {"stemReplace", "text", 3, &kMParams_155[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_156[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"maxDist", "number"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_156[] = {
    {"distance", "number", 2, &kMParams_156[0]},
    {"similarity", "number", 2, &kMParams_156[2]},
    {"ratio", "number", 2, &kMParams_156[4]},
    {"isClose", "bool", 3, &kMParams_156[6]},
    {"normalizedDist", "number", 2, &kMParams_156[9]},
    {"longestCommon", "number", 2, &kMParams_156[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_157[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"n", "number"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_157[] = {
    {"similarity", "number", 2, &kMParams_157[0]},
    {"tokenJaccard", "number", 2, &kMParams_157[2]},
    {"distance", "number", 2, &kMParams_157[4]},
    {"ngramJaccard", "number", 3, &kMParams_157[6]},
    {"overlap", "number", 2, &kMParams_157[9]},
    {"dice", "number", 2, &kMParams_157[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_158[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_158[] = {
    {"editLen", "number", 1, &kMParams_158[0]},
    {"editUpper", "text", 1, &kMParams_158[1]},
    {"editLower", "text", 1, &kMParams_158[2]},
    {"editTrim", "text", 1, &kMParams_158[3]},
    {"editSplit", "list text", 2, &kMParams_158[4]},
    {"editJoin", "text", 2, &kMParams_158[6]},
    {"editReplace", "text", 3, &kMParams_158[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_159[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_159[] = {
    {"tokeLen", "number", 1, &kMParams_159[0]},
    {"tokeUpper", "text", 1, &kMParams_159[1]},
    {"tokeLower", "text", 1, &kMParams_159[2]},
    {"tokeTrim", "text", 1, &kMParams_159[3]},
    {"tokeSplit", "list text", 2, &kMParams_159[4]},
    {"tokeJoin", "text", 2, &kMParams_159[6]},
    {"tokeReplace", "text", 3, &kMParams_159[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_160[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_160[] = {
    {"ngraLen", "number", 1, &kMParams_160[0]},
    {"ngraUpper", "text", 1, &kMParams_160[1]},
    {"ngraLower", "text", 1, &kMParams_160[2]},
    {"ngraTrim", "text", 1, &kMParams_160[3]},
    {"ngraSplit", "list text", 2, &kMParams_160[4]},
    {"ngraJoin", "text", 2, &kMParams_160[6]},
    {"ngraReplace", "text", 3, &kMParams_160[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_161[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_161[] = {
    {"bowLen", "number", 1, &kMParams_161[0]},
    {"bowUpper", "text", 1, &kMParams_161[1]},
    {"bowLower", "text", 1, &kMParams_161[2]},
    {"bowTrim", "text", 1, &kMParams_161[3]},
    {"bowSplit", "list text", 2, &kMParams_161[4]},
    {"bowJoin", "text", 2, &kMParams_161[6]},
    {"bowReplace", "text", 3, &kMParams_161[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_162[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_162[] = {
    {"stopLen", "number", 1, &kMParams_162[0]},
    {"stopUpper", "text", 1, &kMParams_162[1]},
    {"stopLower", "text", 1, &kMParams_162[2]},
    {"stopTrim", "text", 1, &kMParams_162[3]},
    {"stopSplit", "list text", 2, &kMParams_162[4]},
    {"stopJoin", "text", 2, &kMParams_162[6]},
    {"stopReplace", "text", 3, &kMParams_162[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_163[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_163[] = {
    {"phraLen", "number", 1, &kMParams_163[0]},
    {"phraUpper", "text", 1, &kMParams_163[1]},
    {"phraLower", "text", 1, &kMParams_163[2]},
    {"phraTrim", "text", 1, &kMParams_163[3]},
    {"phraSplit", "list text", 2, &kMParams_163[4]},
    {"phraJoin", "text", 2, &kMParams_163[6]},
    {"phraReplace", "text", 3, &kMParams_163[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_164[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_164[] = {
    {"sentLen", "number", 1, &kMParams_164[0]},
    {"sentUpper", "text", 1, &kMParams_164[1]},
    {"sentLower", "text", 1, &kMParams_164[2]},
    {"sentTrim", "text", 1, &kMParams_164[3]},
    {"sentSplit", "list text", 2, &kMParams_164[4]},
    {"sentJoin", "text", 2, &kMParams_164[6]},
    {"sentReplace", "text", 3, &kMParams_164[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_165[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_165[] = {
    {"keywLen", "number", 1, &kMParams_165[0]},
    {"keywUpper", "text", 1, &kMParams_165[1]},
    {"keywLower", "text", 1, &kMParams_165[2]},
    {"keywTrim", "text", 1, &kMParams_165[3]},
    {"keywSplit", "list text", 2, &kMParams_165[4]},
    {"keywJoin", "text", 2, &kMParams_165[6]},
    {"keywReplace", "text", 3, &kMParams_165[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_166[] = {
    {"doc", "text"},
    {"term", "text"},
    {"term", "text"},
    {"corpus", "list text"},
    {"doc", "text"},
    {"term", "text"},
    {"corpus", "list text"},
    {"doc", "text"},
    {"terms", "list text"},
    {"corpus", "list text"},
    {"a", "list number"},
    {"b", "list number"},
    {"doc", "text"},
    {"corpus", "list text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_166[] = {
    {"tf", "number", 2, &kMParams_166[0]},
    {"idf", "number", 2, &kMParams_166[2]},
    {"tfidf", "number", 3, &kMParams_166[4]},
    {"docVector", "list number", 3, &kMParams_166[7]},
    {"cosineSim", "number", 2, &kMParams_166[10]},
    {"rankTerms", "list text", 2, &kMParams_166[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_167[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_167[] = {
    {"overLen", "number", 1, &kMParams_167[0]},
    {"overUpper", "text", 1, &kMParams_167[1]},
    {"overLower", "text", 1, &kMParams_167[2]},
    {"overTrim", "text", 1, &kMParams_167[3]},
    {"overSplit", "list text", 2, &kMParams_167[4]},
    {"overJoin", "text", 2, &kMParams_167[6]},
    {"overReplace", "text", 3, &kMParams_167[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_168[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_168[] = {
    {"simhLen", "number", 1, &kMParams_168[0]},
    {"simhUpper", "text", 1, &kMParams_168[1]},
    {"simhLower", "text", 1, &kMParams_168[2]},
    {"simhTrim", "text", 1, &kMParams_168[3]},
    {"simhSplit", "list text", 2, &kMParams_168[4]},
    {"simhJoin", "text", 2, &kMParams_168[6]},
    {"simhReplace", "text", 3, &kMParams_168[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_169[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_169[] = {
    {"compLen", "number", 1, &kMParams_169[0]},
    {"compUpper", "text", 1, &kMParams_169[1]},
    {"compLower", "text", 1, &kMParams_169[2]},
    {"compTrim", "text", 1, &kMParams_169[3]},
    {"compSplit", "list text", 2, &kMParams_169[4]},
    {"compJoin", "text", 2, &kMParams_169[6]},
    {"compReplace", "text", 3, &kMParams_169[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_170[] = {
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"win", "number"},
    {"v", "list number"},
    {"fast", "number"},
    {"slow", "number"},
    {"v", "list number"},
    {"fast", "number"},
    {"slow", "number"},
    {"v", "list number"},
    {"win", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_170[] = {
    {"sma", "list number", 2, &kMParams_170[0]},
    {"wma", "list number", 2, &kMParams_170[2]},
    {"dema", "list number", 2, &kMParams_170[4]},
    {"crossover", "list number", 3, &kMParams_170[6]},
    {"signal", "number", 3, &kMParams_170[9]},
    {"trend", "number", 2, &kMParams_170[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_171[] = {
    {"v", "list number"},
    {"alpha", "number"},
    {"v", "list number"},
    {"span", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"alpha", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_171[] = {
    {"ema", "list number", 2, &kMParams_171[0]},
    {"emaSpan", "list number", 2, &kMParams_171[2]},
    {"macd", "list number", 1, &kMParams_171[4]},
    {"macdSignal", "list number", 1, &kMParams_171[5]},
    {"histogram", "list number", 1, &kMParams_171[6]},
    {"lastEma", "number", 2, &kMParams_171[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_172[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_172[] = {
    {"autoSum", "number", 1, &kMParams_172[0]},
    {"autoMean", "number", 1, &kMParams_172[1]},
    {"autoMin", "number", 1, &kMParams_172[2]},
    {"autoMax", "number", 1, &kMParams_172[3]},
    {"autoVar", "number", 1, &kMParams_172[4]},
    {"autoStd", "number", 1, &kMParams_172[5]},
    {"autoNorm", "list number", 1, &kMParams_172[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_173[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_173[] = {
    {"seasSum", "number", 1, &kMParams_173[0]},
    {"seasMean", "number", 1, &kMParams_173[1]},
    {"seasMin", "number", 1, &kMParams_173[2]},
    {"seasMax", "number", 1, &kMParams_173[3]},
    {"seasVar", "number", 1, &kMParams_173[4]},
    {"seasStd", "number", 1, &kMParams_173[5]},
    {"seasNorm", "list number", 1, &kMParams_173[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_174[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_174[] = {
    {"decoSum", "number", 1, &kMParams_174[0]},
    {"decoMean", "number", 1, &kMParams_174[1]},
    {"decoMin", "number", 1, &kMParams_174[2]},
    {"decoMax", "number", 1, &kMParams_174[3]},
    {"decoVar", "number", 1, &kMParams_174[4]},
    {"decoStd", "number", 1, &kMParams_174[5]},
    {"decoNorm", "list number", 1, &kMParams_174[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_175[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_175[] = {
    {"foreSum", "number", 1, &kMParams_175[0]},
    {"foreMean", "number", 1, &kMParams_175[1]},
    {"foreMin", "number", 1, &kMParams_175[2]},
    {"foreMax", "number", 1, &kMParams_175[3]},
    {"foreVar", "number", 1, &kMParams_175[4]},
    {"foreStd", "number", 1, &kMParams_175[5]},
    {"foreNorm", "list number", 1, &kMParams_175[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_176[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_176[] = {
    {"anomSum", "number", 1, &kMParams_176[0]},
    {"anomMean", "number", 1, &kMParams_176[1]},
    {"anomMin", "number", 1, &kMParams_176[2]},
    {"anomMax", "number", 1, &kMParams_176[3]},
    {"anomVar", "number", 1, &kMParams_176[4]},
    {"anomStd", "number", 1, &kMParams_176[5]},
    {"anomNorm", "list number", 1, &kMParams_176[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_177[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_177[] = {
    {"rollSum", "number", 1, &kMParams_177[0]},
    {"rollMean", "number", 1, &kMParams_177[1]},
    {"rollMin", "number", 1, &kMParams_177[2]},
    {"rollMax", "number", 1, &kMParams_177[3]},
    {"rollVar", "number", 1, &kMParams_177[4]},
    {"rollStd", "number", 1, &kMParams_177[5]},
    {"rollNorm", "list number", 1, &kMParams_177[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_178[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_178[] = {
    {"cumuSum", "number", 1, &kMParams_178[0]},
    {"cumuMean", "number", 1, &kMParams_178[1]},
    {"cumuMin", "number", 1, &kMParams_178[2]},
    {"cumuMax", "number", 1, &kMParams_178[3]},
    {"cumuVar", "number", 1, &kMParams_178[4]},
    {"cumuStd", "number", 1, &kMParams_178[5]},
    {"cumuNorm", "list number", 1, &kMParams_178[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_179[] = {
    {"v", "list number"},
    {"order", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"period", "number"},
    {"v", "list number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_179[] = {
    {"diff", "list number", 2, &kMParams_179[0]},
    {"pctChange", "list number", 1, &kMParams_179[2]},
    {"logReturn", "list number", 1, &kMParams_179[3]},
    {"cumReturn", "list number", 1, &kMParams_179[4]},
    {"seasonalDiff", "list number", 2, &kMParams_179[5]},
    {"integrate", "list number", 2, &kMParams_179[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_180[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_180[] = {
    {"hullSum", "number", 1, &kMParams_180[0]},
    {"hullMean", "number", 1, &kMParams_180[1]},
    {"hullMin", "number", 1, &kMParams_180[2]},
    {"hullMax", "number", 1, &kMParams_180[3]},
    {"hullVar", "number", 1, &kMParams_180[4]},
    {"hullStd", "number", 1, &kMParams_180[5]},
    {"hullNorm", "list number", 1, &kMParams_180[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_181[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_181[] = {
    {"polySum", "number", 1, &kMParams_181[0]},
    {"polyMean", "number", 1, &kMParams_181[1]},
    {"polyMin", "number", 1, &kMParams_181[2]},
    {"polyMax", "number", 1, &kMParams_181[3]},
    {"polyVar", "number", 1, &kMParams_181[4]},
    {"polyStd", "number", 1, &kMParams_181[5]},
    {"polyNorm", "list number", 1, &kMParams_181[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_182[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_182[] = {
    {"lineSum", "number", 1, &kMParams_182[0]},
    {"lineMean", "number", 1, &kMParams_182[1]},
    {"lineMin", "number", 1, &kMParams_182[2]},
    {"lineMax", "number", 1, &kMParams_182[3]},
    {"lineVar", "number", 1, &kMParams_182[4]},
    {"lineStd", "number", 1, &kMParams_182[5]},
    {"lineNorm", "list number", 1, &kMParams_182[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_183[] = {
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"r", "number"},
    {"r", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {"r", "number"},
    {"px", "number"},
    {"py", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {"r", "number"},
    {"angle", "number"},
    {"r1", "number"},
    {"r2", "number"},
    {"d", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_183[] = {
    {"euclidean2d", "number", 4, &kMParams_183[0]},
    {"area", "number", 1, &kMParams_183[4]},
    {"circumference", "number", 1, &kMParams_183[5]},
    {"contains", "bool", 5, &kMParams_183[6]},
    {"pointAt", "list number", 4, &kMParams_183[11]},
    {"intersectArea", "number", 3, &kMParams_183[15]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_184[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_184[] = {
    {"beziSum", "number", 1, &kMParams_184[0]},
    {"beziMean", "number", 1, &kMParams_184[1]},
    {"beziMin", "number", 1, &kMParams_184[2]},
    {"beziMax", "number", 1, &kMParams_184[3]},
    {"beziVar", "number", 1, &kMParams_184[4]},
    {"beziStd", "number", 1, &kMParams_184[5]},
    {"beziNorm", "list number", 1, &kMParams_184[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_185[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_185[] = {
    {"clipSum", "number", 1, &kMParams_185[0]},
    {"clipMean", "number", 1, &kMParams_185[1]},
    {"clipMin", "number", 1, &kMParams_185[2]},
    {"clipMax", "number", 1, &kMParams_185[3]},
    {"clipVar", "number", 1, &kMParams_185[4]},
    {"clipStd", "number", 1, &kMParams_185[5]},
    {"clipNorm", "list number", 1, &kMParams_185[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_186[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_186[] = {
    {"rotaSum", "number", 1, &kMParams_186[0]},
    {"rotaMean", "number", 1, &kMParams_186[1]},
    {"rotaMin", "number", 1, &kMParams_186[2]},
    {"rotaMax", "number", 1, &kMParams_186[3]},
    {"rotaVar", "number", 1, &kMParams_186[4]},
    {"rotaStd", "number", 1, &kMParams_186[5]},
    {"rotaNorm", "list number", 1, &kMParams_186[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_187[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_187[] = {
    {"scalSum", "number", 1, &kMParams_187[0]},
    {"scalMean", "number", 1, &kMParams_187[1]},
    {"scalMin", "number", 1, &kMParams_187[2]},
    {"scalMax", "number", 1, &kMParams_187[3]},
    {"scalVar", "number", 1, &kMParams_187[4]},
    {"scalStd", "number", 1, &kMParams_187[5]},
    {"scalNorm", "list number", 1, &kMParams_187[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_188[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_188[] = {
    {"inteSum", "number", 1, &kMParams_188[0]},
    {"inteMean", "number", 1, &kMParams_188[1]},
    {"inteMin", "number", 1, &kMParams_188[2]},
    {"inteMax", "number", 1, &kMParams_188[3]},
    {"inteVar", "number", 1, &kMParams_188[4]},
    {"inteStd", "number", 1, &kMParams_188[5]},
    {"inteNorm", "list number", 1, &kMParams_188[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_189[] = {
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"px", "number"},
    {"py", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"points", "list number"},
    {"points", "list number"},
    {"points", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_189[] = {
    {"euclidean2d", "number", 4, &kMParams_189[0]},
    {"manhattan2d", "number", 4, &kMParams_189[4]},
    {"chebyshev2d", "number", 4, &kMParams_189[8]},
    {"pointToLine", "number", 6, &kMParams_189[12]},
    {"pairwiseDist", "list number", 1, &kMParams_189[18]},
    {"centroid2d", "list number", 1, &kMParams_189[19]},
    {"bbox2d", "list number", 1, &kMParams_189[20]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_190[] = {
    {"ip", "text"},
    {"ip", "text"},
    {"n", "number"},
    {"ip", "text"},
    {"ip", "text"},
    {"a", "text"},
    {"b", "text"},
    {"mask", "number"},
    {"ip", "text"},
    {"mask", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_190[] = {
    {"parseOctets", "list number", 1, &kMParams_190[0]},
    {"toInt", "number", 1, &kMParams_190[1]},
    {"fromInt", "text", 1, &kMParams_190[2]},
    {"isPrivate", "bool", 1, &kMParams_190[3]},
    {"isValid", "bool", 1, &kMParams_190[4]},
    {"sameSubnet", "bool", 3, &kMParams_190[5]},
    {"broadcast", "text", 2, &kMParams_190[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_191[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_191[] = {
    {"subnLen", "number", 1, &kMParams_191[0]},
    {"subnUpper", "text", 1, &kMParams_191[1]},
    {"subnLower", "text", 1, &kMParams_191[2]},
    {"subnTrim", "text", 1, &kMParams_191[3]},
    {"subnSplit", "list text", 2, &kMParams_191[4]},
    {"subnJoin", "text", 2, &kMParams_191[6]},
    {"subnReplace", "text", 3, &kMParams_191[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_192[] = {
    {"cidr", "text"},
    {"cidr", "text"},
    {"prefix", "number"},
    {"ip", "text"},
    {"cidr", "text"},
    {"cidr", "text"},
    {"ip", "text"},
    {"cidr", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_192[] = {
    {"prefixLen", "number", 1, &kMParams_192[0]},
    {"hostCount", "number", 1, &kMParams_192[1]},
    {"maskFromPrefix", "number", 1, &kMParams_192[2]},
    {"ipToInt", "number", 1, &kMParams_192[3]},
    {"networkInt", "number", 1, &kMParams_192[4]},
    {"containsIp", "bool", 2, &kMParams_192[5]},
    {"broadcastInt", "number", 1, &kMParams_192[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_193[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_193[] = {
    {"packLen", "number", 1, &kMParams_193[0]},
    {"packUpper", "text", 1, &kMParams_193[1]},
    {"packLower", "text", 1, &kMParams_193[2]},
    {"packTrim", "text", 1, &kMParams_193[3]},
    {"packSplit", "list text", 2, &kMParams_193[4]},
    {"packJoin", "text", 2, &kMParams_193[6]},
    {"packReplace", "text", 3, &kMParams_193[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_194[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_194[] = {
    {"macLen", "number", 1, &kMParams_194[0]},
    {"macUpper", "text", 1, &kMParams_194[1]},
    {"macLower", "text", 1, &kMParams_194[2]},
    {"macTrim", "text", 1, &kMParams_194[3]},
    {"macSplit", "list text", 2, &kMParams_194[4]},
    {"macJoin", "text", 2, &kMParams_194[6]},
    {"macReplace", "text", 3, &kMParams_194[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_195[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_195[] = {
    {"dnsLen", "number", 1, &kMParams_195[0]},
    {"dnsUpper", "text", 1, &kMParams_195[1]},
    {"dnsLower", "text", 1, &kMParams_195[2]},
    {"dnsTrim", "text", 1, &kMParams_195[3]},
    {"dnsSplit", "list text", 2, &kMParams_195[4]},
    {"dnsJoin", "text", 2, &kMParams_195[6]},
    {"dnsReplace", "text", 3, &kMParams_195[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_196[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_196[] = {
    {"portLen", "number", 1, &kMParams_196[0]},
    {"portUpper", "text", 1, &kMParams_196[1]},
    {"portLower", "text", 1, &kMParams_196[2]},
    {"portTrim", "text", 1, &kMParams_196[3]},
    {"portSplit", "list text", 2, &kMParams_196[4]},
    {"portJoin", "text", 2, &kMParams_196[6]},
    {"portReplace", "text", 3, &kMParams_196[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_197[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_197[] = {
    {"routLen", "number", 1, &kMParams_197[0]},
    {"routUpper", "text", 1, &kMParams_197[1]},
    {"routLower", "text", 1, &kMParams_197[2]},
    {"routTrim", "text", 1, &kMParams_197[3]},
    {"routSplit", "list text", 2, &kMParams_197[4]},
    {"routJoin", "text", 2, &kMParams_197[6]},
    {"routReplace", "text", 3, &kMParams_197[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_198[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_198[] = {
    {"pingLen", "number", 1, &kMParams_198[0]},
    {"pingUpper", "text", 1, &kMParams_198[1]},
    {"pingLower", "text", 1, &kMParams_198[2]},
    {"pingTrim", "text", 1, &kMParams_198[3]},
    {"pingSplit", "list text", 2, &kMParams_198[4]},
    {"pingJoin", "text", 2, &kMParams_198[6]},
    {"pingReplace", "text", 3, &kMParams_198[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_199[] = {
    {"data", "list number"},
    {"n", "number"},
    {"sum", "number"},
    {"data", "list number"},
    {"expected", "number"},
    {"src", "list number"},
    {"dst", "list number"},
    {"proto", "number"},
    {"len", "number"},
    {"header", "list number"},
    {"payload", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_199[] = {
    {"ipChecksum", "number", 1, &kMParams_199[0]},
    {"onesComplement", "number", 1, &kMParams_199[1]},
    {"fold32", "number", 1, &kMParams_199[2]},
    {"verify", "bool", 2, &kMParams_199[3]},
    {"pseudoHeader", "list number", 4, &kMParams_199[5]},
    {"tcpChecksum", "number", 2, &kMParams_199[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_200[] = {
    {"board", "list number"},
    {"depth", "number"},
    {"maximizing", "bool"},
    {"board", "list number"},
    {"depth", "number"},
    {"board", "list number"},
    {"board", "list number"},
    {"board", "list number"},
    {"depth", "number"},
    {"color", "number"},
    {"depth", "number"},
    {"board", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_200[] = {
    {"minimax", "number", 3, &kMParams_200[0]},
    {"bestMove", "number", 2, &kMParams_200[3]},
    {"evaluate", "number", 1, &kMParams_200[5]},
    {"isTerminal", "bool", 1, &kMParams_200[6]},
    {"negamax", "number", 3, &kMParams_200[7]},
    {"depthReached", "number", 1, &kMParams_200[10]},
    {"scoreDiff", "number", 1, &kMParams_200[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_201[] = {
    {"board", "list number"},
    {"depth", "number"},
    {"alpha", "number"},
    {"beta", "number"},
    {"maximizing", "bool"},
    {"board", "list number"},
    {"depth", "number"},
    {"board", "list number"},
    {"depth", "number"},
    {"board", "list number"},
    {"board", "list number"},
    {"depth", "number"},
    {"board", "list number"},
    {"board", "list number"},
    {"depth", "number"},
    {"window", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_201[] = {
    {"alphabeta", "number", 5, &kMParams_201[0]},
    {"bestMove", "number", 2, &kMParams_201[5]},
    {"pruneCount", "number", 2, &kMParams_201[7]},
    {"evaluate", "number", 1, &kMParams_201[9]},
    {"search", "number", 2, &kMParams_201[10]},
    {"isWinning", "bool", 1, &kMParams_201[12]},
    {"windowSearch", "number", 3, &kMParams_201[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_202[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"cameFrom", "list number"},
    {"current", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"grid", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_202[] = {
    {"heuristic", "number", 4, &kMParams_202[0]},
    {"astar", "list number", 4, &kMParams_202[4]},
    {"pathCost", "number", 4, &kMParams_202[8]},
    {"reconstruct", "list number", 2, &kMParams_202[12]},
    {"manhattan", "number", 4, &kMParams_202[14]},
    {"octile", "number", 4, &kMParams_202[18]},
    {"openSetSize", "number", 1, &kMParams_202[22]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_203[] = {
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goals", "list number"},
    {"dist", "list number"},
    {"grid", "list number"},
    {"width", "number"},
    {"u", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_203[] = {
    {"gridDijkstra", "list number", 3, &kMParams_203[0]},
    {"shortestCost", "number", 4, &kMParams_203[3]},
    {"reachableCells", "number", 3, &kMParams_203[7]},
    {"multiGoal", "list number", 4, &kMParams_203[10]},
    {"relaxStep", "list number", 4, &kMParams_203[14]},
    {"maxDist", "number", 3, &kMParams_203[18]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_204[] = {
    {"wins", "list number"},
    {"visits", "list number"},
    {"totalVisits", "number"},
    {"explore", "number"},
    {"state", "list number"},
    {"depth", "number"},
    {"state", "list number"},
    {"sims", "number"},
    {"wins", "list number"},
    {"visits", "list number"},
    {"wins", "list number"},
    {"visits", "list number"},
    {"action", "number"},
    {"reward", "number"},
    {"state", "list number"},
    {"actions", "list number"},
    {"wins", "list number"},
    {"visits", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_204[] = {
    {"uctSelect", "number", 4, &kMParams_204[0]},
    {"rollout", "number", 2, &kMParams_204[4]},
    {"simulate", "number", 2, &kMParams_204[6]},
    {"bestAction", "number", 2, &kMParams_204[8]},
    {"updateStats", "list number", 4, &kMParams_204[10]},
    {"treePolicy", "number", 2, &kMParams_204[14]},
    {"mctsValue", "number", 2, &kMParams_204[16]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_205[] = {
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"path", "list number"},
    {"grid", "list number"},
    {"width", "number"},
    {"path", "list number"},
    {"step", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"goal", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_205[] = {
    {"bfsPath", "list number", 4, &kMParams_205[0]},
    {"pathLen", "number", 4, &kMParams_205[4]},
    {"lineOfSight", "bool", 6, &kMParams_205[8]},
    {"smoothPath", "list number", 3, &kMParams_205[14]},
    {"waypoints", "list number", 2, &kMParams_205[17]},
    {"navCost", "number", 4, &kMParams_205[19]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_206[] = {
    {"px", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"path", "list number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"cx", "number"},
    {"cy", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_206[] = {
    {"pointInTri", "bool", 8, &kMParams_206[0]},
    {"triArea", "number", 6, &kMParams_206[8]},
    {"portalMid", "list number", 2, &kMParams_206[14]},
    {"navDistance", "number", 2, &kMParams_206[16]},
    {"funnelCost", "number", 1, &kMParams_206[18]},
    {"centroid", "list number", 6, &kMParams_206[19]},
    {"meshQuality", "number", 6, &kMParams_206[25]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_207[] = {
    {"scores", "list number"},
    {"scores", "list number"},
    {"scores", "list number"},
    {"keys", "list text"},
    {"values", "list number"},
    {"key", "text"},
    {"keys", "list text"},
    {"values", "list number"},
    {"key", "text"},
    {"val", "number"},
    {"last", "number"},
    {"now", "number"},
    {"cd", "number"},
    {"weights", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_207[] = {
    {"evalSelector", "number", 1, &kMParams_207[0]},
    {"evalSequence", "number", 1, &kMParams_207[1]},
    {"evalParallel", "number", 1, &kMParams_207[2]},
    {"blackboardGet", "number", 3, &kMParams_207[3]},
    {"blackboardSet", "list number", 4, &kMParams_207[6]},
    {"cooldownReady", "bool", 3, &kMParams_207[10]},
    {"weightedPick", "number", 1, &kMParams_207[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_208[] = {
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"newVal", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {"grid", "list number"},
    {"width", "number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_208[] = {
    {"floodFill", "list number", 4, &kMParams_208[0]},
    {"connectedRegion", "number", 3, &kMParams_208[4]},
    {"countRegions", "number", 2, &kMParams_208[7]},
    {"fillDist", "list number", 3, &kMParams_208[9]},
    {"reachable", "number", 3, &kMParams_208[12]},
    {"boundary", "list number", 3, &kMParams_208[15]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_209[] = {
    {"children", "list number"},
    {"depths", "list number"},
    {"values", "list number"},
    {"maxNode", "bool"},
    {"values", "list number"},
    {"probs", "list number"},
    {"alpha", "number"},
    {"beta", "number"},
    {"branching", "number"},
    {"depth", "number"},
    {"moves", "list number"},
    {"scores", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_209[] = {
    {"branchingFactor", "number", 1, &kMParams_209[0]},
    {"treeDepth", "number", 1, &kMParams_209[1]},
    {"minimaxLeaf", "number", 2, &kMParams_209[2]},
    {"expectimax", "number", 2, &kMParams_209[4]},
    {"alphaBetaWindow", "list number", 2, &kMParams_209[6]},
    {"gameTreeSize", "number", 2, &kMParams_209[8]},
    {"plyCount", "number", 1, &kMParams_209[10]},
    {"bestChild", "number", 1, &kMParams_209[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibModuleSpec kComplexModules[] = {
    {"graphbfs", "graphbfs", kMFuncs_0, 7, "cx/complex_libs.hpp", false},
    {"graphdfs", "graphdfs", kMFuncs_1, 7, "cx/complex_libs.hpp", false},
    {"graphdijk", "graphdijk", kMFuncs_2, 7, "cx/complex_libs.hpp", false},
    {"graphtopo", "graphtopo", kMFuncs_3, 7, "cx/complex_libs.hpp", false},
    {"graphcc", "graphcc", kMFuncs_4, 7, "cx/complex_libs.hpp", false},
    {"graphcycle", "graphcycle", kMFuncs_5, 7, "cx/complex_libs.hpp", false},
    {"graphmst", "graphmst", kMFuncs_6, 6, "cx/complex_libs.hpp", false},
    {"graphshort", "graphshort", kMFuncs_7, 6, "cx/complex_libs.hpp", false},
    {"graphbellman", "graphbellman", kMFuncs_8, 6, "cx/complex_libs.hpp", false},
    {"graphfloyd", "graphfloyd", kMFuncs_9, 6, "cx/complex_libs.hpp", false},
    {"graphprim", "graphprim", kMFuncs_10, 7, "cx/complex_libs.hpp", false},
    {"graphkruskal", "graphkruskal", kMFuncs_11, 7, "cx/complex_libs.hpp", false},
    {"graphbipart", "graphbipart", kMFuncs_12, 7, "cx/complex_libs.hpp", false},
    {"grapheuler", "grapheuler", kMFuncs_13, 7, "cx/complex_libs.hpp", false},
    {"graphham", "graphham", kMFuncs_14, 7, "cx/complex_libs.hpp", false},
    {"graphclique", "graphclique", kMFuncs_15, 7, "cx/complex_libs.hpp", false},
    {"graphcolor", "graphcolor", kMFuncs_16, 7, "cx/complex_libs.hpp", false},
    {"graphflow", "graphflow", kMFuncs_17, 7, "cx/complex_libs.hpp", false},
    {"graphmatch", "graphmatch", kMFuncs_18, 7, "cx/complex_libs.hpp", false},
    {"graphcent", "graphcent", kMFuncs_19, 7, "cx/complex_libs.hpp", false},
    {"statregress", "statregress", kMFuncs_20, 8, "cx/complex_libs.hpp", false},
    {"statcorrel", "statcorrel", kMFuncs_21, 7, "cx/complex_libs.hpp", false},
    {"statquartile", "statquartile", kMFuncs_22, 7, "cx/complex_libs.hpp", false},
    {"stathistogram", "stathistogram", kMFuncs_23, 6, "cx/complex_libs.hpp", false},
    {"statanova", "statanova", kMFuncs_24, 6, "cx/complex_libs.hpp", false},
    {"statttest", "statttest", kMFuncs_25, 6, "cx/complex_libs.hpp", false},
    {"statchi2", "statchi2", kMFuncs_26, 6, "cx/complex_libs.hpp", false},
    {"statnormcdf", "statnormcdf", kMFuncs_27, 6, "cx/complex_libs.hpp", false},
    {"statzscore", "statzscore", kMFuncs_28, 6, "cx/complex_libs.hpp", false},
    {"statcovar", "statcovar", kMFuncs_29, 8, "cx/complex_libs.hpp", false},
    {"statrmse", "statrmse", kMFuncs_30, 6, "cx/complex_libs.hpp", false},
    {"statmape", "statmape", kMFuncs_31, 6, "cx/complex_libs.hpp", false},
    {"statmedian", "statmedian", kMFuncs_32, 6, "cx/complex_libs.hpp", false},
    {"statmode", "statmode", kMFuncs_33, 6, "cx/complex_libs.hpp", false},
    {"statskew", "statskew", kMFuncs_34, 6, "cx/complex_libs.hpp", false},
    {"statkurt", "statkurt", kMFuncs_35, 6, "cx/complex_libs.hpp", false},
    {"statbootstrap", "statbootstrap", kMFuncs_36, 6, "cx/complex_libs.hpp", false},
    {"statoutlier", "statoutlier", kMFuncs_37, 6, "cx/complex_libs.hpp", false},
    {"statpercentile", "statpercentile", kMFuncs_38, 7, "cx/complex_libs.hpp", false},
    {"statbayes", "statbayes", kMFuncs_39, 7, "cx/complex_libs.hpp", false},
    {"mlkmeans", "mlkmeans", kMFuncs_40, 6, "cx/complex_libs.hpp", false},
    {"mllinear", "mllinear", kMFuncs_41, 6, "cx/complex_libs.hpp", false},
    {"mlnaivebayes", "mlnaivebayes", kMFuncs_42, 6, "cx/complex_libs.hpp", false},
    {"mltfidf", "mltfidf", kMFuncs_43, 7, "cx/complex_libs.hpp", false},
    {"mlcosine", "mlcosine", kMFuncs_44, 6, "cx/complex_libs.hpp", false},
    {"mlsvm", "mlsvm", kMFuncs_45, 7, "cx/complex_libs.hpp", false},
    {"mlpca", "mlpca", kMFuncs_46, 7, "cx/complex_libs.hpp", false},
    {"mlentropy", "mlentropy", kMFuncs_47, 7, "cx/complex_libs.hpp", false},
    {"mlkldiv", "mlkldiv", kMFuncs_48, 7, "cx/complex_libs.hpp", false},
    {"mlgradient", "mlgradient", kMFuncs_49, 7, "cx/complex_libs.hpp", false},
    {"mlsoftmax", "mlsoftmax", kMFuncs_50, 6, "cx/complex_libs.hpp", false},
    {"mlperceptron", "mlperceptron", kMFuncs_51, 6, "cx/complex_libs.hpp", false},
    {"mlcrossval", "mlcrossval", kMFuncs_52, 7, "cx/complex_libs.hpp", false},
    {"mlfeature", "mlfeature", kMFuncs_53, 7, "cx/complex_libs.hpp", false},
    {"mlnormalize", "mlnormalize", kMFuncs_54, 7, "cx/complex_libs.hpp", false},
    {"mldistance", "mldistance", kMFuncs_55, 7, "cx/complex_libs.hpp", false},
    {"mlcluster", "mlcluster", kMFuncs_56, 7, "cx/complex_libs.hpp", false},
    {"mlnearest", "mlnearest", kMFuncs_57, 7, "cx/complex_libs.hpp", false},
    {"mldecision", "mldecision", kMFuncs_58, 7, "cx/complex_libs.hpp", false},
    {"mlensemble", "mlensemble", kMFuncs_59, 7, "cx/complex_libs.hpp", false},
    {"cryptsha256", "cryptsha256", kMFuncs_60, 8, "cx/complex_libs.hpp", false},
    {"cryptsha1", "cryptsha1", kMFuncs_61, 8, "cx/complex_libs.hpp", false},
    {"cryptmd5", "cryptmd5", kMFuncs_62, 8, "cx/complex_libs.hpp", false},
    {"crypthmac", "crypthmac", kMFuncs_63, 8, "cx/complex_libs.hpp", false},
    {"cryptxor", "cryptxor", kMFuncs_64, 7, "cx/complex_libs.hpp", false},
    {"cryptcaesar", "cryptcaesar", kMFuncs_65, 6, "cx/complex_libs.hpp", false},
    {"cryptvigenere", "cryptvigenere", kMFuncs_66, 8, "cx/complex_libs.hpp", false},
    {"cryptbase64", "cryptbase64", kMFuncs_67, 6, "cx/complex_libs.hpp", false},
    {"cryptrot13", "cryptrot13", kMFuncs_68, 8, "cx/complex_libs.hpp", false},
    {"cryptaeslite", "cryptaeslite", kMFuncs_69, 8, "cx/complex_libs.hpp", false},
    {"cryptpbkdf", "cryptpbkdf", kMFuncs_70, 8, "cx/complex_libs.hpp", false},
    {"cryptscrypt", "cryptscrypt", kMFuncs_71, 8, "cx/complex_libs.hpp", false},
    {"cryptnonce", "cryptnonce", kMFuncs_72, 8, "cx/complex_libs.hpp", false},
    {"cryptcrc32", "cryptcrc32", kMFuncs_73, 6, "cx/complex_libs.hpp", false},
    {"cryptparity", "cryptparity", kMFuncs_74, 8, "cx/complex_libs.hpp", false},
    {"comprle", "comprle", kMFuncs_75, 7, "cx/complex_libs.hpp", false},
    {"compdelta", "compdelta", kMFuncs_76, 6, "cx/complex_libs.hpp", false},
    {"compresshuff", "compresshuff", kMFuncs_77, 6, "cx/complex_libs.hpp", false},
    {"complz77", "complz77", kMFuncs_78, 6, "cx/complex_libs.hpp", false},
    {"complzw", "complzw", kMFuncs_79, 6, "cx/complex_libs.hpp", false},
    {"comprunlen", "comprunlen", kMFuncs_80, 6, "cx/complex_libs.hpp", false},
    {"compbitpack", "compbitpack", kMFuncs_81, 6, "cx/complex_libs.hpp", false},
    {"compvarint", "compvarint", kMFuncs_82, 6, "cx/complex_libs.hpp", false},
    {"compdict", "compdict", kMFuncs_83, 6, "cx/complex_libs.hpp", false},
    {"compframe", "compframe", kMFuncs_84, 6, "cx/complex_libs.hpp", false},
    {"parsejsonadv", "parsejsonadv", kMFuncs_85, 7, "cx/complex_libs.hpp", false},
    {"parsexml", "parsexml", kMFuncs_86, 7, "cx/complex_libs.hpp", false},
    {"parseini", "parseini", kMFuncs_87, 7, "cx/complex_libs.hpp", false},
    {"parsetoml", "parsetoml", kMFuncs_88, 7, "cx/complex_libs.hpp", false},
    {"parsepath", "parsepath", kMFuncs_89, 7, "cx/complex_libs.hpp", false},
    {"parseyaml", "parseyaml", kMFuncs_90, 7, "cx/complex_libs.hpp", false},
    {"parsecsvadv", "parsecsvadv", kMFuncs_91, 8, "cx/complex_libs.hpp", false},
    {"parsehtml", "parsehtml", kMFuncs_92, 7, "cx/complex_libs.hpp", false},
    {"parselog", "parselog", kMFuncs_93, 7, "cx/complex_libs.hpp", false},
    {"parseuri", "parseuri", kMFuncs_94, 7, "cx/complex_libs.hpp", false},
    {"parsemime", "parsemime", kMFuncs_95, 7, "cx/complex_libs.hpp", false},
    {"parsehex", "parsehex", kMFuncs_96, 6, "cx/complex_libs.hpp", false},
    {"parsebinary", "parsebinary", kMFuncs_97, 7, "cx/complex_libs.hpp", false},
    {"parsetemplate", "parsetemplate", kMFuncs_98, 7, "cx/complex_libs.hpp", false},
    {"parseexpr", "parseexpr", kMFuncs_99, 7, "cx/complex_libs.hpp", false},
    {"csvfilter", "csvfilter", kMFuncs_100, 8, "cx/complex_libs.hpp", false},
    {"csvgroup", "csvgroup", kMFuncs_101, 6, "cx/complex_libs.hpp", false},
    {"csvaggregate", "csvaggregate", kMFuncs_102, 8, "cx/complex_libs.hpp", false},
    {"csvjoin", "csvjoin", kMFuncs_103, 8, "cx/complex_libs.hpp", false},
    {"csvpivot", "csvpivot", kMFuncs_104, 8, "cx/complex_libs.hpp", false},
    {"csvsort", "csvsort", kMFuncs_105, 6, "cx/complex_libs.hpp", false},
    {"csvselect", "csvselect", kMFuncs_106, 8, "cx/complex_libs.hpp", false},
    {"csvdistinct", "csvdistinct", kMFuncs_107, 8, "cx/complex_libs.hpp", false},
    {"csvlimit", "csvlimit", kMFuncs_108, 8, "cx/complex_libs.hpp", false},
    {"csvhaving", "csvhaving", kMFuncs_109, 8, "cx/complex_libs.hpp", false},
    {"csvunion", "csvunion", kMFuncs_110, 8, "cx/complex_libs.hpp", false},
    {"csvwindow", "csvwindow", kMFuncs_111, 8, "cx/complex_libs.hpp", false},
    {"csvnormalize", "csvnormalize", kMFuncs_112, 8, "cx/complex_libs.hpp", false},
    {"csvrollup", "csvrollup", kMFuncs_113, 8, "cx/complex_libs.hpp", false},
    {"csvsample", "csvsample", kMFuncs_114, 8, "cx/complex_libs.hpp", false},
    {"simmonte", "simmonte", kMFuncs_115, 6, "cx/complex_libs.hpp", false},
    {"simmarkov", "simmarkov", kMFuncs_116, 6, "cx/complex_libs.hpp", false},
    {"simrandomwalk", "simrandomwalk", kMFuncs_117, 8, "cx/complex_libs.hpp", false},
    {"simbrownian", "simbrownian", kMFuncs_118, 8, "cx/complex_libs.hpp", false},
    {"simpoisson", "simpoisson", kMFuncs_119, 8, "cx/complex_libs.hpp", false},
    {"simqueue", "simqueue", kMFuncs_120, 8, "cx/complex_libs.hpp", false},
    {"siminventory", "siminventory", kMFuncs_121, 8, "cx/complex_libs.hpp", false},
    {"simdiscrete", "simdiscrete", kMFuncs_122, 8, "cx/complex_libs.hpp", false},
    {"simlorenz", "simlorenz", kMFuncs_123, 8, "cx/complex_libs.hpp", false},
    {"simbirth", "simbirth", kMFuncs_124, 8, "cx/complex_libs.hpp", false},
    {"finoption", "finoption", kMFuncs_125, 7, "cx/complex_libs.hpp", false},
    {"finbond", "finbond", kMFuncs_126, 6, "cx/complex_libs.hpp", false},
    {"finportfolio", "finportfolio", kMFuncs_127, 7, "cx/complex_libs.hpp", false},
    {"finblack", "finblack", kMFuncs_128, 7, "cx/complex_libs.hpp", false},
    {"fingreeks", "fingreeks", kMFuncs_129, 7, "cx/complex_libs.hpp", false},
    {"finyield", "finyield", kMFuncs_130, 7, "cx/complex_libs.hpp", false},
    {"finsharpe", "finsharpe", kMFuncs_131, 6, "cx/complex_libs.hpp", false},
    {"finvar", "finvar", kMFuncs_132, 7, "cx/complex_libs.hpp", false},
    {"finforex", "finforex", kMFuncs_133, 7, "cx/complex_libs.hpp", false},
    {"finamort", "finamort", kMFuncs_134, 7, "cx/complex_libs.hpp", false},
    {"finfutures", "finfutures", kMFuncs_135, 7, "cx/complex_libs.hpp", false},
    {"finswap", "finswap", kMFuncs_136, 7, "cx/complex_libs.hpp", false},
    {"finrisk", "finrisk", kMFuncs_137, 7, "cx/complex_libs.hpp", false},
    {"finhedge", "finhedge", kMFuncs_138, 7, "cx/complex_libs.hpp", false},
    {"findividend", "findividend", kMFuncs_139, 7, "cx/complex_libs.hpp", false},
    {"sigconv", "sigconv", kMFuncs_140, 6, "cx/complex_libs.hpp", false},
    {"sigfft", "sigfft", kMFuncs_141, 6, "cx/complex_libs.hpp", false},
    {"sigpoly", "sigpoly", kMFuncs_142, 7, "cx/complex_libs.hpp", false},
    {"sigeigen", "sigeigen", kMFuncs_143, 7, "cx/complex_libs.hpp", false},
    {"sigmatrix", "sigmatrix", kMFuncs_144, 7, "cx/complex_libs.hpp", false},
    {"sigintegral", "sigintegral", kMFuncs_145, 7, "cx/complex_libs.hpp", false},
    {"sigderivative", "sigderivative", kMFuncs_146, 7, "cx/complex_libs.hpp", false},
    {"sigfilter", "sigfilter", kMFuncs_147, 6, "cx/complex_libs.hpp", false},
    {"sigwavelet", "sigwavelet", kMFuncs_148, 7, "cx/complex_libs.hpp", false},
    {"sigresample", "sigresample", kMFuncs_149, 7, "cx/complex_libs.hpp", false},
    {"siginterpolate", "siginterpolate", kMFuncs_150, 7, "cx/complex_libs.hpp", false},
    {"sigspline", "sigspline", kMFuncs_151, 7, "cx/complex_libs.hpp", false},
    {"sigcorrel", "sigcorrel", kMFuncs_152, 7, "cx/complex_libs.hpp", false},
    {"sigautocorr", "sigautocorr", kMFuncs_153, 7, "cx/complex_libs.hpp", false},
    {"sigpower", "sigpower", kMFuncs_154, 7, "cx/complex_libs.hpp", false},
    {"nlpstem", "nlpstem", kMFuncs_155, 7, "cx/complex_libs.hpp", false},
    {"nlplevenshtein", "nlplevenshtein", kMFuncs_156, 6, "cx/complex_libs.hpp", false},
    {"nlpjaccard", "nlpjaccard", kMFuncs_157, 6, "cx/complex_libs.hpp", false},
    {"nlpedit", "nlpedit", kMFuncs_158, 7, "cx/complex_libs.hpp", false},
    {"nlptoken", "nlptoken", kMFuncs_159, 7, "cx/complex_libs.hpp", false},
    {"nlpngram", "nlpngram", kMFuncs_160, 7, "cx/complex_libs.hpp", false},
    {"nlpbow", "nlpbow", kMFuncs_161, 7, "cx/complex_libs.hpp", false},
    {"nlpstop", "nlpstop", kMFuncs_162, 7, "cx/complex_libs.hpp", false},
    {"nlpphrase", "nlpphrase", kMFuncs_163, 7, "cx/complex_libs.hpp", false},
    {"nlpsentiment", "nlpsentiment", kMFuncs_164, 7, "cx/complex_libs.hpp", false},
    {"nlpkeyword", "nlpkeyword", kMFuncs_165, 7, "cx/complex_libs.hpp", false},
    {"nlptfidf", "nlptfidf", kMFuncs_166, 6, "cx/complex_libs.hpp", false},
    {"nlpoverlap", "nlpoverlap", kMFuncs_167, 7, "cx/complex_libs.hpp", false},
    {"nlpsimhash", "nlpsimhash", kMFuncs_168, 7, "cx/complex_libs.hpp", false},
    {"nlpcompress", "nlpcompress", kMFuncs_169, 7, "cx/complex_libs.hpp", false},
    {"tsma", "tsma", kMFuncs_170, 6, "cx/complex_libs.hpp", false},
    {"tsema", "tsema", kMFuncs_171, 6, "cx/complex_libs.hpp", false},
    {"tsautocorr", "tsautocorr", kMFuncs_172, 7, "cx/complex_libs.hpp", false},
    {"tsseason", "tsseason", kMFuncs_173, 7, "cx/complex_libs.hpp", false},
    {"tsdecompose", "tsdecompose", kMFuncs_174, 7, "cx/complex_libs.hpp", false},
    {"tsforecast", "tsforecast", kMFuncs_175, 7, "cx/complex_libs.hpp", false},
    {"tsanomaly", "tsanomaly", kMFuncs_176, 7, "cx/complex_libs.hpp", false},
    {"tsrolling", "tsrolling", kMFuncs_177, 7, "cx/complex_libs.hpp", false},
    {"tscumulative", "tscumulative", kMFuncs_178, 7, "cx/complex_libs.hpp", false},
    {"tsdiff", "tsdiff", kMFuncs_179, 6, "cx/complex_libs.hpp", false},
    {"geomhull", "geomhull", kMFuncs_180, 7, "cx/complex_libs.hpp", false},
    {"geompolygon", "geompolygon", kMFuncs_181, 7, "cx/complex_libs.hpp", false},
    {"geomline", "geomline", kMFuncs_182, 7, "cx/complex_libs.hpp", false},
    {"geomcircle", "geomcircle", kMFuncs_183, 6, "cx/complex_libs.hpp", false},
    {"geombezier", "geombezier", kMFuncs_184, 7, "cx/complex_libs.hpp", false},
    {"geomclip", "geomclip", kMFuncs_185, 7, "cx/complex_libs.hpp", false},
    {"geomrotate", "geomrotate", kMFuncs_186, 7, "cx/complex_libs.hpp", false},
    {"geomscale", "geomscale", kMFuncs_187, 7, "cx/complex_libs.hpp", false},
    {"geomintersect", "geomintersect", kMFuncs_188, 7, "cx/complex_libs.hpp", false},
    {"geomdistance", "geomdistance", kMFuncs_189, 7, "cx/complex_libs.hpp", false},
    {"netip", "netip", kMFuncs_190, 7, "cx/complex_libs.hpp", false},
    {"netsubnet", "netsubnet", kMFuncs_191, 7, "cx/complex_libs.hpp", false},
    {"netcidr", "netcidr", kMFuncs_192, 7, "cx/complex_libs.hpp", false},
    {"netpacket", "netpacket", kMFuncs_193, 7, "cx/complex_libs.hpp", false},
    {"netmac", "netmac", kMFuncs_194, 7, "cx/complex_libs.hpp", false},
    {"netdns", "netdns", kMFuncs_195, 7, "cx/complex_libs.hpp", false},
    {"netport", "netport", kMFuncs_196, 7, "cx/complex_libs.hpp", false},
    {"netroute", "netroute", kMFuncs_197, 7, "cx/complex_libs.hpp", false},
    {"netping", "netping", kMFuncs_198, 7, "cx/complex_libs.hpp", false},
    {"netchecksum", "netchecksum", kMFuncs_199, 6, "cx/complex_libs.hpp", false},
    {"gameminimax", "gameminimax", kMFuncs_200, 7, "cx/complex_libs.hpp", false},
    {"gamealphabeta", "gamealphabeta", kMFuncs_201, 7, "cx/complex_libs.hpp", false},
    {"gameastar", "gameastar", kMFuncs_202, 7, "cx/complex_libs.hpp", false},
    {"gamedijkstra", "gamedijkstra", kMFuncs_203, 6, "cx/complex_libs.hpp", false},
    {"gamemcts", "gamemcts", kMFuncs_204, 7, "cx/complex_libs.hpp", false},
    {"gamepathfind", "gamepathfind", kMFuncs_205, 6, "cx/complex_libs.hpp", false},
    {"gamenavmesh", "gamenavmesh", kMFuncs_206, 7, "cx/complex_libs.hpp", false},
    {"gamebehavior", "gamebehavior", kMFuncs_207, 7, "cx/complex_libs.hpp", false},
    {"gameflood", "gameflood", kMFuncs_208, 6, "cx/complex_libs.hpp", false},
    {"gametree", "gametree", kMFuncs_209, 8, "cx/complex_libs.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kComplexModuleCount = 210;

} // namespace

const StdlibModuleSpec* complexCatalogFindModule(const std::string& name) {
    for (std::size_t i = 0; i < kComplexModuleCount; ++i) {
        if (name == kComplexModules[i].importName || name == kComplexModules[i].moduleName)
            return &kComplexModules[i];
    }
    return nullptr;
}

bool complexCatalogIsComplexModule(const std::string& name) {
    return complexCatalogFindModule(name) != nullptr;
}

} // namespace afrilang
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

const StdlibParamSpec kMParams_210[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_210[] = {
    {"astarGridPath", "list number", 8, &kMParams_210[0]},
    {"floodCount", "number", 6, &kMParams_210[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_210[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_211[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_211[] = {
    {"astarGridPath", "list number", 8, &kMParams_211[0]},
    {"floodCount", "number", 6, &kMParams_211[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_211[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_212[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_212[] = {
    {"astarGridPath", "list number", 8, &kMParams_212[0]},
    {"floodCount", "number", 6, &kMParams_212[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_212[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_213[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_213[] = {
    {"astarGridPath", "list number", 8, &kMParams_213[0]},
    {"floodCount", "number", 6, &kMParams_213[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_213[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_214[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_214[] = {
    {"astarGridPath", "list number", 8, &kMParams_214[0]},
    {"floodCount", "number", 6, &kMParams_214[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_214[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_215[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_215[] = {
    {"astarGridPath", "list number", 8, &kMParams_215[0]},
    {"floodCount", "number", 6, &kMParams_215[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_215[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_216[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_216[] = {
    {"astarGridPath", "list number", 8, &kMParams_216[0]},
    {"floodCount", "number", 6, &kMParams_216[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_216[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_217[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_217[] = {
    {"astarGridPath", "list number", 8, &kMParams_217[0]},
    {"floodCount", "number", 6, &kMParams_217[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_217[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_218[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_218[] = {
    {"astarGridPath", "list number", 8, &kMParams_218[0]},
    {"floodCount", "number", 6, &kMParams_218[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_218[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_219[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_219[] = {
    {"astarGridPath", "list number", 8, &kMParams_219[0]},
    {"floodCount", "number", 6, &kMParams_219[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_219[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_220[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_220[] = {
    {"astarGridPath", "list number", 8, &kMParams_220[0]},
    {"floodCount", "number", 6, &kMParams_220[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_220[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_221[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_221[] = {
    {"astarGridPath", "list number", 8, &kMParams_221[0]},
    {"floodCount", "number", 6, &kMParams_221[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_221[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_222[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_222[] = {
    {"astarGridPath", "list number", 8, &kMParams_222[0]},
    {"floodCount", "number", 6, &kMParams_222[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_222[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_223[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_223[] = {
    {"astarGridPath", "list number", 8, &kMParams_223[0]},
    {"floodCount", "number", 6, &kMParams_223[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_223[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_224[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_224[] = {
    {"astarGridPath", "list number", 8, &kMParams_224[0]},
    {"floodCount", "number", 6, &kMParams_224[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_224[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_225[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_225[] = {
    {"astarGridPath", "list number", 8, &kMParams_225[0]},
    {"floodCount", "number", 6, &kMParams_225[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_225[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_226[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_226[] = {
    {"astarGridPath", "list number", 8, &kMParams_226[0]},
    {"floodCount", "number", 6, &kMParams_226[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_226[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_227[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_227[] = {
    {"astarGridPath", "list number", 8, &kMParams_227[0]},
    {"floodCount", "number", 6, &kMParams_227[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_227[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_228[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_228[] = {
    {"astarGridPath", "list number", 8, &kMParams_228[0]},
    {"floodCount", "number", 6, &kMParams_228[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_228[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_229[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_229[] = {
    {"astarGridPath", "list number", 8, &kMParams_229[0]},
    {"floodCount", "number", 6, &kMParams_229[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_229[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_230[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_230[] = {
    {"astarGridPath", "list number", 8, &kMParams_230[0]},
    {"floodCount", "number", 6, &kMParams_230[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_230[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_231[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_231[] = {
    {"astarGridPath", "list number", 8, &kMParams_231[0]},
    {"floodCount", "number", 6, &kMParams_231[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_231[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_232[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_232[] = {
    {"astarGridPath", "list number", 8, &kMParams_232[0]},
    {"floodCount", "number", 6, &kMParams_232[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_232[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_233[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_233[] = {
    {"astarGridPath", "list number", 8, &kMParams_233[0]},
    {"floodCount", "number", 6, &kMParams_233[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_233[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_234[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_234[] = {
    {"astarGridPath", "list number", 8, &kMParams_234[0]},
    {"floodCount", "number", 6, &kMParams_234[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_234[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_235[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_235[] = {
    {"astarGridPath", "list number", 8, &kMParams_235[0]},
    {"floodCount", "number", 6, &kMParams_235[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_235[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_236[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_236[] = {
    {"astarGridPath", "list number", 8, &kMParams_236[0]},
    {"floodCount", "number", 6, &kMParams_236[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_236[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_237[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_237[] = {
    {"astarGridPath", "list number", 8, &kMParams_237[0]},
    {"floodCount", "number", 6, &kMParams_237[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_237[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_238[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_238[] = {
    {"astarGridPath", "list number", 8, &kMParams_238[0]},
    {"floodCount", "number", 6, &kMParams_238[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_238[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_239[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_239[] = {
    {"astarGridPath", "list number", 8, &kMParams_239[0]},
    {"floodCount", "number", 6, &kMParams_239[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_239[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_240[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_240[] = {
    {"astarGridPath", "list number", 8, &kMParams_240[0]},
    {"floodCount", "number", 6, &kMParams_240[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_240[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_241[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_241[] = {
    {"astarGridPath", "list number", 8, &kMParams_241[0]},
    {"floodCount", "number", 6, &kMParams_241[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_241[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_242[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_242[] = {
    {"astarGridPath", "list number", 8, &kMParams_242[0]},
    {"floodCount", "number", 6, &kMParams_242[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_242[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_243[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_243[] = {
    {"astarGridPath", "list number", 8, &kMParams_243[0]},
    {"floodCount", "number", 6, &kMParams_243[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_243[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_244[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_244[] = {
    {"astarGridPath", "list number", 8, &kMParams_244[0]},
    {"floodCount", "number", 6, &kMParams_244[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_244[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_245[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_245[] = {
    {"astarGridPath", "list number", 8, &kMParams_245[0]},
    {"floodCount", "number", 6, &kMParams_245[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_245[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_246[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_246[] = {
    {"astarGridPath", "list number", 8, &kMParams_246[0]},
    {"floodCount", "number", 6, &kMParams_246[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_246[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_247[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_247[] = {
    {"astarGridPath", "list number", 8, &kMParams_247[0]},
    {"floodCount", "number", 6, &kMParams_247[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_247[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_248[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_248[] = {
    {"astarGridPath", "list number", 8, &kMParams_248[0]},
    {"floodCount", "number", 6, &kMParams_248[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_248[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_249[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_249[] = {
    {"astarGridPath", "list number", 8, &kMParams_249[0]},
    {"floodCount", "number", 6, &kMParams_249[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_249[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_250[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_250[] = {
    {"astarGridPath", "list number", 8, &kMParams_250[0]},
    {"floodCount", "number", 6, &kMParams_250[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_250[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_251[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_251[] = {
    {"astarGridPath", "list number", 8, &kMParams_251[0]},
    {"floodCount", "number", 6, &kMParams_251[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_251[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_252[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_252[] = {
    {"astarGridPath", "list number", 8, &kMParams_252[0]},
    {"floodCount", "number", 6, &kMParams_252[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_252[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_253[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_253[] = {
    {"astarGridPath", "list number", 8, &kMParams_253[0]},
    {"floodCount", "number", 6, &kMParams_253[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_253[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_254[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_254[] = {
    {"astarGridPath", "list number", 8, &kMParams_254[0]},
    {"floodCount", "number", 6, &kMParams_254[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_254[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_255[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_255[] = {
    {"astarGridPath", "list number", 8, &kMParams_255[0]},
    {"floodCount", "number", 6, &kMParams_255[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_255[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_256[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_256[] = {
    {"astarGridPath", "list number", 8, &kMParams_256[0]},
    {"floodCount", "number", 6, &kMParams_256[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_256[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_257[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_257[] = {
    {"astarGridPath", "list number", 8, &kMParams_257[0]},
    {"floodCount", "number", 6, &kMParams_257[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_257[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_258[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_258[] = {
    {"astarGridPath", "list number", 8, &kMParams_258[0]},
    {"floodCount", "number", 6, &kMParams_258[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_258[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_259[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_259[] = {
    {"astarGridPath", "list number", 8, &kMParams_259[0]},
    {"floodCount", "number", 6, &kMParams_259[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_259[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_260[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_260[] = {
    {"astarGridPath", "list number", 8, &kMParams_260[0]},
    {"floodCount", "number", 6, &kMParams_260[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_260[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_261[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_261[] = {
    {"astarGridPath", "list number", 8, &kMParams_261[0]},
    {"floodCount", "number", 6, &kMParams_261[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_261[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_262[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_262[] = {
    {"astarGridPath", "list number", 8, &kMParams_262[0]},
    {"floodCount", "number", 6, &kMParams_262[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_262[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_263[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_263[] = {
    {"astarGridPath", "list number", 8, &kMParams_263[0]},
    {"floodCount", "number", 6, &kMParams_263[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_263[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_264[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_264[] = {
    {"astarGridPath", "list number", 8, &kMParams_264[0]},
    {"floodCount", "number", 6, &kMParams_264[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_264[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_265[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_265[] = {
    {"astarGridPath", "list number", 8, &kMParams_265[0]},
    {"floodCount", "number", 6, &kMParams_265[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_265[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_266[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_266[] = {
    {"astarGridPath", "list number", 8, &kMParams_266[0]},
    {"floodCount", "number", 6, &kMParams_266[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_266[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_267[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_267[] = {
    {"astarGridPath", "list number", 8, &kMParams_267[0]},
    {"floodCount", "number", 6, &kMParams_267[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_267[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_268[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_268[] = {
    {"astarGridPath", "list number", 8, &kMParams_268[0]},
    {"floodCount", "number", 6, &kMParams_268[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_268[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_269[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_269[] = {
    {"astarGridPath", "list number", 8, &kMParams_269[0]},
    {"floodCount", "number", 6, &kMParams_269[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_269[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_270[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_270[] = {
    {"astarGridPath", "list number", 8, &kMParams_270[0]},
    {"floodCount", "number", 6, &kMParams_270[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_270[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_271[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_271[] = {
    {"astarGridPath", "list number", 8, &kMParams_271[0]},
    {"floodCount", "number", 6, &kMParams_271[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_271[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_272[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_272[] = {
    {"astarGridPath", "list number", 8, &kMParams_272[0]},
    {"floodCount", "number", 6, &kMParams_272[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_272[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_273[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_273[] = {
    {"astarGridPath", "list number", 8, &kMParams_273[0]},
    {"floodCount", "number", 6, &kMParams_273[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_273[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_274[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_274[] = {
    {"astarGridPath", "list number", 8, &kMParams_274[0]},
    {"floodCount", "number", 6, &kMParams_274[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_274[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_275[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_275[] = {
    {"astarGridPath", "list number", 8, &kMParams_275[0]},
    {"floodCount", "number", 6, &kMParams_275[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_275[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_276[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_276[] = {
    {"astarGridPath", "list number", 8, &kMParams_276[0]},
    {"floodCount", "number", 6, &kMParams_276[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_276[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_277[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_277[] = {
    {"astarGridPath", "list number", 8, &kMParams_277[0]},
    {"floodCount", "number", 6, &kMParams_277[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_277[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_278[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_278[] = {
    {"astarGridPath", "list number", 8, &kMParams_278[0]},
    {"floodCount", "number", 6, &kMParams_278[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_278[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_279[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_279[] = {
    {"astarGridPath", "list number", 8, &kMParams_279[0]},
    {"floodCount", "number", 6, &kMParams_279[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_279[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_280[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_280[] = {
    {"astarGridPath", "list number", 8, &kMParams_280[0]},
    {"floodCount", "number", 6, &kMParams_280[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_280[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_281[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_281[] = {
    {"astarGridPath", "list number", 8, &kMParams_281[0]},
    {"floodCount", "number", 6, &kMParams_281[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_281[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_282[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_282[] = {
    {"astarGridPath", "list number", 8, &kMParams_282[0]},
    {"floodCount", "number", 6, &kMParams_282[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_282[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_283[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_283[] = {
    {"astarGridPath", "list number", 8, &kMParams_283[0]},
    {"floodCount", "number", 6, &kMParams_283[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_283[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_284[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_284[] = {
    {"astarGridPath", "list number", 8, &kMParams_284[0]},
    {"floodCount", "number", 6, &kMParams_284[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_284[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_285[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_285[] = {
    {"astarGridPath", "list number", 8, &kMParams_285[0]},
    {"floodCount", "number", 6, &kMParams_285[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_285[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_286[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_286[] = {
    {"astarGridPath", "list number", 8, &kMParams_286[0]},
    {"floodCount", "number", 6, &kMParams_286[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_286[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_287[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_287[] = {
    {"astarGridPath", "list number", 8, &kMParams_287[0]},
    {"floodCount", "number", 6, &kMParams_287[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_287[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_288[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_288[] = {
    {"astarGridPath", "list number", 8, &kMParams_288[0]},
    {"floodCount", "number", 6, &kMParams_288[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_288[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_289[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_289[] = {
    {"astarGridPath", "list number", 8, &kMParams_289[0]},
    {"floodCount", "number", 6, &kMParams_289[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_289[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_290[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_290[] = {
    {"astarGridPath", "list number", 8, &kMParams_290[0]},
    {"floodCount", "number", 6, &kMParams_290[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_290[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_291[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_291[] = {
    {"astarGridPath", "list number", 8, &kMParams_291[0]},
    {"floodCount", "number", 6, &kMParams_291[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_291[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_292[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_292[] = {
    {"astarGridPath", "list number", 8, &kMParams_292[0]},
    {"floodCount", "number", 6, &kMParams_292[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_292[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_293[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_293[] = {
    {"astarGridPath", "list number", 8, &kMParams_293[0]},
    {"floodCount", "number", 6, &kMParams_293[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_293[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_294[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_294[] = {
    {"astarGridPath", "list number", 8, &kMParams_294[0]},
    {"floodCount", "number", 6, &kMParams_294[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_294[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_295[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_295[] = {
    {"astarGridPath", "list number", 8, &kMParams_295[0]},
    {"floodCount", "number", 6, &kMParams_295[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_295[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_296[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_296[] = {
    {"astarGridPath", "list number", 8, &kMParams_296[0]},
    {"floodCount", "number", 6, &kMParams_296[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_296[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_297[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_297[] = {
    {"astarGridPath", "list number", 8, &kMParams_297[0]},
    {"floodCount", "number", 6, &kMParams_297[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_297[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_298[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_298[] = {
    {"astarGridPath", "list number", 8, &kMParams_298[0]},
    {"floodCount", "number", 6, &kMParams_298[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_298[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_299[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_299[] = {
    {"astarGridPath", "list number", 8, &kMParams_299[0]},
    {"floodCount", "number", 6, &kMParams_299[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_299[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_300[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_300[] = {
    {"astarGridPath", "list number", 8, &kMParams_300[0]},
    {"floodCount", "number", 6, &kMParams_300[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_300[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_301[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_301[] = {
    {"astarGridPath", "list number", 8, &kMParams_301[0]},
    {"floodCount", "number", 6, &kMParams_301[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_301[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_302[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_302[] = {
    {"astarGridPath", "list number", 8, &kMParams_302[0]},
    {"floodCount", "number", 6, &kMParams_302[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_302[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_303[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_303[] = {
    {"astarGridPath", "list number", 8, &kMParams_303[0]},
    {"floodCount", "number", 6, &kMParams_303[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_303[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_304[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_304[] = {
    {"astarGridPath", "list number", 8, &kMParams_304[0]},
    {"floodCount", "number", 6, &kMParams_304[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_304[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_305[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_305[] = {
    {"astarGridPath", "list number", 8, &kMParams_305[0]},
    {"floodCount", "number", 6, &kMParams_305[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_305[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_306[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_306[] = {
    {"astarGridPath", "list number", 8, &kMParams_306[0]},
    {"floodCount", "number", 6, &kMParams_306[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_306[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_307[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_307[] = {
    {"astarGridPath", "list number", 8, &kMParams_307[0]},
    {"floodCount", "number", 6, &kMParams_307[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_307[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_308[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_308[] = {
    {"astarGridPath", "list number", 8, &kMParams_308[0]},
    {"floodCount", "number", 6, &kMParams_308[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_308[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_309[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_309[] = {
    {"astarGridPath", "list number", 8, &kMParams_309[0]},
    {"floodCount", "number", 6, &kMParams_309[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_309[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_310[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_310[] = {
    {"astarGridPath", "list number", 8, &kMParams_310[0]},
    {"floodCount", "number", 6, &kMParams_310[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_310[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_311[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_311[] = {
    {"astarGridPath", "list number", 8, &kMParams_311[0]},
    {"floodCount", "number", 6, &kMParams_311[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_311[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_312[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_312[] = {
    {"astarGridPath", "list number", 8, &kMParams_312[0]},
    {"floodCount", "number", 6, &kMParams_312[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_312[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_313[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_313[] = {
    {"astarGridPath", "list number", 8, &kMParams_313[0]},
    {"floodCount", "number", 6, &kMParams_313[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_313[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_314[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_314[] = {
    {"astarGridPath", "list number", 8, &kMParams_314[0]},
    {"floodCount", "number", 6, &kMParams_314[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_314[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_315[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_315[] = {
    {"astarGridPath", "list number", 8, &kMParams_315[0]},
    {"floodCount", "number", 6, &kMParams_315[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_315[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_316[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_316[] = {
    {"astarGridPath", "list number", 8, &kMParams_316[0]},
    {"floodCount", "number", 6, &kMParams_316[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_316[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_317[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_317[] = {
    {"astarGridPath", "list number", 8, &kMParams_317[0]},
    {"floodCount", "number", 6, &kMParams_317[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_317[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_318[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_318[] = {
    {"astarGridPath", "list number", 8, &kMParams_318[0]},
    {"floodCount", "number", 6, &kMParams_318[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_318[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_319[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_319[] = {
    {"astarGridPath", "list number", 8, &kMParams_319[0]},
    {"floodCount", "number", 6, &kMParams_319[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_319[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_320[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_320[] = {
    {"astarGridPath", "list number", 8, &kMParams_320[0]},
    {"floodCount", "number", 6, &kMParams_320[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_320[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_321[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_321[] = {
    {"astarGridPath", "list number", 8, &kMParams_321[0]},
    {"floodCount", "number", 6, &kMParams_321[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_321[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_322[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_322[] = {
    {"astarGridPath", "list number", 8, &kMParams_322[0]},
    {"floodCount", "number", 6, &kMParams_322[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_322[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_323[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_323[] = {
    {"astarGridPath", "list number", 8, &kMParams_323[0]},
    {"floodCount", "number", 6, &kMParams_323[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_323[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_324[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_324[] = {
    {"astarGridPath", "list number", 8, &kMParams_324[0]},
    {"floodCount", "number", 6, &kMParams_324[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_324[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_325[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_325[] = {
    {"astarGridPath", "list number", 8, &kMParams_325[0]},
    {"floodCount", "number", 6, &kMParams_325[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_325[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_326[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_326[] = {
    {"astarGridPath", "list number", 8, &kMParams_326[0]},
    {"floodCount", "number", 6, &kMParams_326[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_326[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_327[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_327[] = {
    {"astarGridPath", "list number", 8, &kMParams_327[0]},
    {"floodCount", "number", 6, &kMParams_327[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_327[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_328[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_328[] = {
    {"astarGridPath", "list number", 8, &kMParams_328[0]},
    {"floodCount", "number", 6, &kMParams_328[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_328[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_329[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_329[] = {
    {"astarGridPath", "list number", 8, &kMParams_329[0]},
    {"floodCount", "number", 6, &kMParams_329[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_329[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_330[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_330[] = {
    {"astarGridPath", "list number", 8, &kMParams_330[0]},
    {"floodCount", "number", 6, &kMParams_330[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_330[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_331[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_331[] = {
    {"astarGridPath", "list number", 8, &kMParams_331[0]},
    {"floodCount", "number", 6, &kMParams_331[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_331[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_332[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_332[] = {
    {"astarGridPath", "list number", 8, &kMParams_332[0]},
    {"floodCount", "number", 6, &kMParams_332[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_332[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_333[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_333[] = {
    {"astarGridPath", "list number", 8, &kMParams_333[0]},
    {"floodCount", "number", 6, &kMParams_333[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_333[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_334[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_334[] = {
    {"astarGridPath", "list number", 8, &kMParams_334[0]},
    {"floodCount", "number", 6, &kMParams_334[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_334[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_335[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_335[] = {
    {"astarGridPath", "list number", 8, &kMParams_335[0]},
    {"floodCount", "number", 6, &kMParams_335[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_335[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_336[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_336[] = {
    {"astarGridPath", "list number", 8, &kMParams_336[0]},
    {"floodCount", "number", 6, &kMParams_336[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_336[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_337[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_337[] = {
    {"astarGridPath", "list number", 8, &kMParams_337[0]},
    {"floodCount", "number", 6, &kMParams_337[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_337[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_338[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_338[] = {
    {"astarGridPath", "list number", 8, &kMParams_338[0]},
    {"floodCount", "number", 6, &kMParams_338[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_338[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_339[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_339[] = {
    {"astarGridPath", "list number", 8, &kMParams_339[0]},
    {"floodCount", "number", 6, &kMParams_339[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_339[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_340[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_340[] = {
    {"astarGridPath", "list number", 8, &kMParams_340[0]},
    {"floodCount", "number", 6, &kMParams_340[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_340[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_341[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_341[] = {
    {"astarGridPath", "list number", 8, &kMParams_341[0]},
    {"floodCount", "number", 6, &kMParams_341[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_341[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_342[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_342[] = {
    {"astarGridPath", "list number", 8, &kMParams_342[0]},
    {"floodCount", "number", 6, &kMParams_342[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_342[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_343[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_343[] = {
    {"astarGridPath", "list number", 8, &kMParams_343[0]},
    {"floodCount", "number", 6, &kMParams_343[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_343[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_344[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_344[] = {
    {"astarGridPath", "list number", 8, &kMParams_344[0]},
    {"floodCount", "number", 6, &kMParams_344[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_344[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_345[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_345[] = {
    {"astarGridPath", "list number", 8, &kMParams_345[0]},
    {"floodCount", "number", 6, &kMParams_345[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_345[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_346[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_346[] = {
    {"astarGridPath", "list number", 8, &kMParams_346[0]},
    {"floodCount", "number", 6, &kMParams_346[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_346[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_347[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_347[] = {
    {"astarGridPath", "list number", 8, &kMParams_347[0]},
    {"floodCount", "number", 6, &kMParams_347[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_347[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_348[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_348[] = {
    {"astarGridPath", "list number", 8, &kMParams_348[0]},
    {"floodCount", "number", 6, &kMParams_348[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_348[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_349[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_349[] = {
    {"astarGridPath", "list number", 8, &kMParams_349[0]},
    {"floodCount", "number", 6, &kMParams_349[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_349[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_350[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_350[] = {
    {"astarGridPath", "list number", 8, &kMParams_350[0]},
    {"floodCount", "number", 6, &kMParams_350[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_350[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_351[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_351[] = {
    {"astarGridPath", "list number", 8, &kMParams_351[0]},
    {"floodCount", "number", 6, &kMParams_351[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_351[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_352[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_352[] = {
    {"astarGridPath", "list number", 8, &kMParams_352[0]},
    {"floodCount", "number", 6, &kMParams_352[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_352[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_353[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_353[] = {
    {"astarGridPath", "list number", 8, &kMParams_353[0]},
    {"floodCount", "number", 6, &kMParams_353[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_353[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_354[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_354[] = {
    {"astarGridPath", "list number", 8, &kMParams_354[0]},
    {"floodCount", "number", 6, &kMParams_354[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_354[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_355[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_355[] = {
    {"astarGridPath", "list number", 8, &kMParams_355[0]},
    {"floodCount", "number", 6, &kMParams_355[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_355[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_356[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_356[] = {
    {"astarGridPath", "list number", 8, &kMParams_356[0]},
    {"floodCount", "number", 6, &kMParams_356[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_356[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_357[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_357[] = {
    {"astarGridPath", "list number", 8, &kMParams_357[0]},
    {"floodCount", "number", 6, &kMParams_357[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_357[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_358[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_358[] = {
    {"astarGridPath", "list number", 8, &kMParams_358[0]},
    {"floodCount", "number", 6, &kMParams_358[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_358[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_359[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_359[] = {
    {"astarGridPath", "list number", 8, &kMParams_359[0]},
    {"floodCount", "number", 6, &kMParams_359[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_359[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_360[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_360[] = {
    {"astarGridPath", "list number", 8, &kMParams_360[0]},
    {"floodCount", "number", 6, &kMParams_360[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_360[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_361[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_361[] = {
    {"astarGridPath", "list number", 8, &kMParams_361[0]},
    {"floodCount", "number", 6, &kMParams_361[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_361[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_362[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_362[] = {
    {"astarGridPath", "list number", 8, &kMParams_362[0]},
    {"floodCount", "number", 6, &kMParams_362[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_362[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_363[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_363[] = {
    {"astarGridPath", "list number", 8, &kMParams_363[0]},
    {"floodCount", "number", 6, &kMParams_363[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_363[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_364[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_364[] = {
    {"astarGridPath", "list number", 8, &kMParams_364[0]},
    {"floodCount", "number", 6, &kMParams_364[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_364[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_365[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_365[] = {
    {"astarGridPath", "list number", 8, &kMParams_365[0]},
    {"floodCount", "number", 6, &kMParams_365[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_365[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_366[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_366[] = {
    {"astarGridPath", "list number", 8, &kMParams_366[0]},
    {"floodCount", "number", 6, &kMParams_366[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_366[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_367[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_367[] = {
    {"astarGridPath", "list number", 8, &kMParams_367[0]},
    {"floodCount", "number", 6, &kMParams_367[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_367[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_368[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_368[] = {
    {"astarGridPath", "list number", 8, &kMParams_368[0]},
    {"floodCount", "number", 6, &kMParams_368[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_368[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_369[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_369[] = {
    {"astarGridPath", "list number", 8, &kMParams_369[0]},
    {"floodCount", "number", 6, &kMParams_369[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_369[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_370[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_370[] = {
    {"astarGridPath", "list number", 8, &kMParams_370[0]},
    {"floodCount", "number", 6, &kMParams_370[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_370[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_371[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_371[] = {
    {"astarGridPath", "list number", 8, &kMParams_371[0]},
    {"floodCount", "number", 6, &kMParams_371[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_371[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_372[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_372[] = {
    {"astarGridPath", "list number", 8, &kMParams_372[0]},
    {"floodCount", "number", 6, &kMParams_372[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_372[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_373[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_373[] = {
    {"astarGridPath", "list number", 8, &kMParams_373[0]},
    {"floodCount", "number", 6, &kMParams_373[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_373[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_374[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_374[] = {
    {"astarGridPath", "list number", 8, &kMParams_374[0]},
    {"floodCount", "number", 6, &kMParams_374[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_374[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_375[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_375[] = {
    {"astarGridPath", "list number", 8, &kMParams_375[0]},
    {"floodCount", "number", 6, &kMParams_375[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_375[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_376[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_376[] = {
    {"astarGridPath", "list number", 8, &kMParams_376[0]},
    {"floodCount", "number", 6, &kMParams_376[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_376[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_377[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_377[] = {
    {"astarGridPath", "list number", 8, &kMParams_377[0]},
    {"floodCount", "number", 6, &kMParams_377[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_377[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_378[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_378[] = {
    {"astarGridPath", "list number", 8, &kMParams_378[0]},
    {"floodCount", "number", 6, &kMParams_378[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_378[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_379[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_379[] = {
    {"astarGridPath", "list number", 8, &kMParams_379[0]},
    {"floodCount", "number", 6, &kMParams_379[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_379[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_380[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_380[] = {
    {"astarGridPath", "list number", 8, &kMParams_380[0]},
    {"floodCount", "number", 6, &kMParams_380[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_380[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_381[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_381[] = {
    {"astarGridPath", "list number", 8, &kMParams_381[0]},
    {"floodCount", "number", 6, &kMParams_381[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_381[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_382[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_382[] = {
    {"astarGridPath", "list number", 8, &kMParams_382[0]},
    {"floodCount", "number", 6, &kMParams_382[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_382[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_383[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_383[] = {
    {"astarGridPath", "list number", 8, &kMParams_383[0]},
    {"floodCount", "number", 6, &kMParams_383[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_383[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_384[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_384[] = {
    {"astarGridPath", "list number", 8, &kMParams_384[0]},
    {"floodCount", "number", 6, &kMParams_384[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_384[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_385[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_385[] = {
    {"astarGridPath", "list number", 8, &kMParams_385[0]},
    {"floodCount", "number", 6, &kMParams_385[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_385[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_386[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_386[] = {
    {"astarGridPath", "list number", 8, &kMParams_386[0]},
    {"floodCount", "number", 6, &kMParams_386[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_386[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_387[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_387[] = {
    {"astarGridPath", "list number", 8, &kMParams_387[0]},
    {"floodCount", "number", 6, &kMParams_387[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_387[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_388[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_388[] = {
    {"astarGridPath", "list number", 8, &kMParams_388[0]},
    {"floodCount", "number", 6, &kMParams_388[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_388[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_389[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_389[] = {
    {"astarGridPath", "list number", 8, &kMParams_389[0]},
    {"floodCount", "number", 6, &kMParams_389[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_389[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_390[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_390[] = {
    {"astarGridPath", "list number", 8, &kMParams_390[0]},
    {"floodCount", "number", 6, &kMParams_390[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_390[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_391[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_391[] = {
    {"astarGridPath", "list number", 8, &kMParams_391[0]},
    {"floodCount", "number", 6, &kMParams_391[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_391[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_392[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_392[] = {
    {"astarGridPath", "list number", 8, &kMParams_392[0]},
    {"floodCount", "number", 6, &kMParams_392[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_392[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_393[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_393[] = {
    {"astarGridPath", "list number", 8, &kMParams_393[0]},
    {"floodCount", "number", 6, &kMParams_393[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_393[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_394[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_394[] = {
    {"astarGridPath", "list number", 8, &kMParams_394[0]},
    {"floodCount", "number", 6, &kMParams_394[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_394[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_395[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_395[] = {
    {"astarGridPath", "list number", 8, &kMParams_395[0]},
    {"floodCount", "number", 6, &kMParams_395[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_395[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_396[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_396[] = {
    {"astarGridPath", "list number", 8, &kMParams_396[0]},
    {"floodCount", "number", 6, &kMParams_396[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_396[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_397[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_397[] = {
    {"astarGridPath", "list number", 8, &kMParams_397[0]},
    {"floodCount", "number", 6, &kMParams_397[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_397[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_398[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_398[] = {
    {"astarGridPath", "list number", 8, &kMParams_398[0]},
    {"floodCount", "number", 6, &kMParams_398[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_398[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_399[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_399[] = {
    {"astarGridPath", "list number", 8, &kMParams_399[0]},
    {"floodCount", "number", 6, &kMParams_399[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_399[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_400[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_400[] = {
    {"astarGridPath", "list number", 8, &kMParams_400[0]},
    {"floodCount", "number", 6, &kMParams_400[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_400[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_401[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_401[] = {
    {"astarGridPath", "list number", 8, &kMParams_401[0]},
    {"floodCount", "number", 6, &kMParams_401[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_401[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_402[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_402[] = {
    {"astarGridPath", "list number", 8, &kMParams_402[0]},
    {"floodCount", "number", 6, &kMParams_402[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_402[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_403[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_403[] = {
    {"astarGridPath", "list number", 8, &kMParams_403[0]},
    {"floodCount", "number", 6, &kMParams_403[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_403[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_404[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_404[] = {
    {"astarGridPath", "list number", 8, &kMParams_404[0]},
    {"floodCount", "number", 6, &kMParams_404[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_404[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_405[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_405[] = {
    {"astarGridPath", "list number", 8, &kMParams_405[0]},
    {"floodCount", "number", 6, &kMParams_405[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_405[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_406[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_406[] = {
    {"astarGridPath", "list number", 8, &kMParams_406[0]},
    {"floodCount", "number", 6, &kMParams_406[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_406[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_407[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_407[] = {
    {"astarGridPath", "list number", 8, &kMParams_407[0]},
    {"floodCount", "number", 6, &kMParams_407[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_407[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_408[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_408[] = {
    {"astarGridPath", "list number", 8, &kMParams_408[0]},
    {"floodCount", "number", 6, &kMParams_408[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_408[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_409[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_409[] = {
    {"astarGridPath", "list number", 8, &kMParams_409[0]},
    {"floodCount", "number", 6, &kMParams_409[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_409[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_410[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_410[] = {
    {"astarGridPath", "list number", 8, &kMParams_410[0]},
    {"floodCount", "number", 6, &kMParams_410[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_410[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_411[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_411[] = {
    {"astarGridPath", "list number", 8, &kMParams_411[0]},
    {"floodCount", "number", 6, &kMParams_411[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_411[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_412[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_412[] = {
    {"astarGridPath", "list number", 8, &kMParams_412[0]},
    {"floodCount", "number", 6, &kMParams_412[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_412[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_413[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_413[] = {
    {"astarGridPath", "list number", 8, &kMParams_413[0]},
    {"floodCount", "number", 6, &kMParams_413[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_413[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_414[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_414[] = {
    {"astarGridPath", "list number", 8, &kMParams_414[0]},
    {"floodCount", "number", 6, &kMParams_414[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_414[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_415[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_415[] = {
    {"astarGridPath", "list number", 8, &kMParams_415[0]},
    {"floodCount", "number", 6, &kMParams_415[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_415[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_416[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_416[] = {
    {"astarGridPath", "list number", 8, &kMParams_416[0]},
    {"floodCount", "number", 6, &kMParams_416[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_416[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_417[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_417[] = {
    {"astarGridPath", "list number", 8, &kMParams_417[0]},
    {"floodCount", "number", 6, &kMParams_417[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_417[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_418[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_418[] = {
    {"astarGridPath", "list number", 8, &kMParams_418[0]},
    {"floodCount", "number", 6, &kMParams_418[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_418[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_419[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_419[] = {
    {"astarGridPath", "list number", 8, &kMParams_419[0]},
    {"floodCount", "number", 6, &kMParams_419[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_419[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_420[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_420[] = {
    {"astarGridPath", "list number", 8, &kMParams_420[0]},
    {"floodCount", "number", 6, &kMParams_420[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_420[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_421[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_421[] = {
    {"astarGridPath", "list number", 8, &kMParams_421[0]},
    {"floodCount", "number", 6, &kMParams_421[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_421[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_422[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_422[] = {
    {"astarGridPath", "list number", 8, &kMParams_422[0]},
    {"floodCount", "number", 6, &kMParams_422[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_422[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_423[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_423[] = {
    {"astarGridPath", "list number", 8, &kMParams_423[0]},
    {"floodCount", "number", 6, &kMParams_423[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_423[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_424[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_424[] = {
    {"astarGridPath", "list number", 8, &kMParams_424[0]},
    {"floodCount", "number", 6, &kMParams_424[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_424[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_425[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_425[] = {
    {"astarGridPath", "list number", 8, &kMParams_425[0]},
    {"floodCount", "number", 6, &kMParams_425[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_425[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_426[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_426[] = {
    {"astarGridPath", "list number", 8, &kMParams_426[0]},
    {"floodCount", "number", 6, &kMParams_426[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_426[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_427[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_427[] = {
    {"astarGridPath", "list number", 8, &kMParams_427[0]},
    {"floodCount", "number", 6, &kMParams_427[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_427[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_428[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_428[] = {
    {"astarGridPath", "list number", 8, &kMParams_428[0]},
    {"floodCount", "number", 6, &kMParams_428[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_428[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_429[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_429[] = {
    {"astarGridPath", "list number", 8, &kMParams_429[0]},
    {"floodCount", "number", 6, &kMParams_429[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_429[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_430[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_430[] = {
    {"astarGridPath", "list number", 8, &kMParams_430[0]},
    {"floodCount", "number", 6, &kMParams_430[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_430[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_431[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_431[] = {
    {"astarGridPath", "list number", 8, &kMParams_431[0]},
    {"floodCount", "number", 6, &kMParams_431[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_431[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_432[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_432[] = {
    {"astarGridPath", "list number", 8, &kMParams_432[0]},
    {"floodCount", "number", 6, &kMParams_432[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_432[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_433[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_433[] = {
    {"astarGridPath", "list number", 8, &kMParams_433[0]},
    {"floodCount", "number", 6, &kMParams_433[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_433[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_434[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_434[] = {
    {"astarGridPath", "list number", 8, &kMParams_434[0]},
    {"floodCount", "number", 6, &kMParams_434[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_434[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_435[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_435[] = {
    {"astarGridPath", "list number", 8, &kMParams_435[0]},
    {"floodCount", "number", 6, &kMParams_435[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_435[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_436[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_436[] = {
    {"astarGridPath", "list number", 8, &kMParams_436[0]},
    {"floodCount", "number", 6, &kMParams_436[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_436[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_437[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_437[] = {
    {"astarGridPath", "list number", 8, &kMParams_437[0]},
    {"floodCount", "number", 6, &kMParams_437[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_437[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_438[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_438[] = {
    {"astarGridPath", "list number", 8, &kMParams_438[0]},
    {"floodCount", "number", 6, &kMParams_438[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_438[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_439[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_439[] = {
    {"astarGridPath", "list number", 8, &kMParams_439[0]},
    {"floodCount", "number", 6, &kMParams_439[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_439[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_440[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_440[] = {
    {"astarGridPath", "list number", 8, &kMParams_440[0]},
    {"floodCount", "number", 6, &kMParams_440[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_440[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_441[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_441[] = {
    {"astarGridPath", "list number", 8, &kMParams_441[0]},
    {"floodCount", "number", 6, &kMParams_441[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_441[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_442[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_442[] = {
    {"astarGridPath", "list number", 8, &kMParams_442[0]},
    {"floodCount", "number", 6, &kMParams_442[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_442[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_443[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_443[] = {
    {"astarGridPath", "list number", 8, &kMParams_443[0]},
    {"floodCount", "number", 6, &kMParams_443[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_443[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_444[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_444[] = {
    {"astarGridPath", "list number", 8, &kMParams_444[0]},
    {"floodCount", "number", 6, &kMParams_444[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_444[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_445[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_445[] = {
    {"astarGridPath", "list number", 8, &kMParams_445[0]},
    {"floodCount", "number", 6, &kMParams_445[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_445[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_446[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_446[] = {
    {"astarGridPath", "list number", 8, &kMParams_446[0]},
    {"floodCount", "number", 6, &kMParams_446[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_446[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_447[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_447[] = {
    {"astarGridPath", "list number", 8, &kMParams_447[0]},
    {"floodCount", "number", 6, &kMParams_447[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_447[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_448[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_448[] = {
    {"astarGridPath", "list number", 8, &kMParams_448[0]},
    {"floodCount", "number", 6, &kMParams_448[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_448[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_449[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_449[] = {
    {"astarGridPath", "list number", 8, &kMParams_449[0]},
    {"floodCount", "number", 6, &kMParams_449[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_449[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_450[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_450[] = {
    {"astarGridPath", "list number", 8, &kMParams_450[0]},
    {"floodCount", "number", 6, &kMParams_450[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_450[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_451[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_451[] = {
    {"astarGridPath", "list number", 8, &kMParams_451[0]},
    {"floodCount", "number", 6, &kMParams_451[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_451[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_452[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_452[] = {
    {"astarGridPath", "list number", 8, &kMParams_452[0]},
    {"floodCount", "number", 6, &kMParams_452[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_452[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_453[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_453[] = {
    {"astarGridPath", "list number", 8, &kMParams_453[0]},
    {"floodCount", "number", 6, &kMParams_453[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_453[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_454[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_454[] = {
    {"astarGridPath", "list number", 8, &kMParams_454[0]},
    {"floodCount", "number", 6, &kMParams_454[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_454[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_455[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_455[] = {
    {"astarGridPath", "list number", 8, &kMParams_455[0]},
    {"floodCount", "number", 6, &kMParams_455[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_455[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_456[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_456[] = {
    {"astarGridPath", "list number", 8, &kMParams_456[0]},
    {"floodCount", "number", 6, &kMParams_456[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_456[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_457[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_457[] = {
    {"astarGridPath", "list number", 8, &kMParams_457[0]},
    {"floodCount", "number", 6, &kMParams_457[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_457[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_458[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_458[] = {
    {"astarGridPath", "list number", 8, &kMParams_458[0]},
    {"floodCount", "number", 6, &kMParams_458[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_458[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_459[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_459[] = {
    {"astarGridPath", "list number", 8, &kMParams_459[0]},
    {"floodCount", "number", 6, &kMParams_459[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_459[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_460[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_460[] = {
    {"astarGridPath", "list number", 8, &kMParams_460[0]},
    {"floodCount", "number", 6, &kMParams_460[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_460[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_461[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_461[] = {
    {"astarGridPath", "list number", 8, &kMParams_461[0]},
    {"floodCount", "number", 6, &kMParams_461[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_461[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_462[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_462[] = {
    {"astarGridPath", "list number", 8, &kMParams_462[0]},
    {"floodCount", "number", 6, &kMParams_462[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_462[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_463[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_463[] = {
    {"astarGridPath", "list number", 8, &kMParams_463[0]},
    {"floodCount", "number", 6, &kMParams_463[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_463[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_464[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_464[] = {
    {"astarGridPath", "list number", 8, &kMParams_464[0]},
    {"floodCount", "number", 6, &kMParams_464[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_464[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_465[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_465[] = {
    {"astarGridPath", "list number", 8, &kMParams_465[0]},
    {"floodCount", "number", 6, &kMParams_465[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_465[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_466[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_466[] = {
    {"astarGridPath", "list number", 8, &kMParams_466[0]},
    {"floodCount", "number", 6, &kMParams_466[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_466[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_467[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_467[] = {
    {"astarGridPath", "list number", 8, &kMParams_467[0]},
    {"floodCount", "number", 6, &kMParams_467[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_467[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_468[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_468[] = {
    {"astarGridPath", "list number", 8, &kMParams_468[0]},
    {"floodCount", "number", 6, &kMParams_468[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_468[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_469[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_469[] = {
    {"astarGridPath", "list number", 8, &kMParams_469[0]},
    {"floodCount", "number", 6, &kMParams_469[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_469[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_470[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_470[] = {
    {"astarGridPath", "list number", 8, &kMParams_470[0]},
    {"floodCount", "number", 6, &kMParams_470[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_470[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_471[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_471[] = {
    {"astarGridPath", "list number", 8, &kMParams_471[0]},
    {"floodCount", "number", 6, &kMParams_471[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_471[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_472[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_472[] = {
    {"astarGridPath", "list number", 8, &kMParams_472[0]},
    {"floodCount", "number", 6, &kMParams_472[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_472[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_473[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_473[] = {
    {"astarGridPath", "list number", 8, &kMParams_473[0]},
    {"floodCount", "number", 6, &kMParams_473[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_473[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_474[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_474[] = {
    {"astarGridPath", "list number", 8, &kMParams_474[0]},
    {"floodCount", "number", 6, &kMParams_474[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_474[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_475[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_475[] = {
    {"astarGridPath", "list number", 8, &kMParams_475[0]},
    {"floodCount", "number", 6, &kMParams_475[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_475[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_476[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_476[] = {
    {"astarGridPath", "list number", 8, &kMParams_476[0]},
    {"floodCount", "number", 6, &kMParams_476[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_476[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_477[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_477[] = {
    {"astarGridPath", "list number", 8, &kMParams_477[0]},
    {"floodCount", "number", 6, &kMParams_477[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_477[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_478[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_478[] = {
    {"astarGridPath", "list number", 8, &kMParams_478[0]},
    {"floodCount", "number", 6, &kMParams_478[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_478[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_479[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_479[] = {
    {"astarGridPath", "list number", 8, &kMParams_479[0]},
    {"floodCount", "number", 6, &kMParams_479[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_479[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_480[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_480[] = {
    {"astarGridPath", "list number", 8, &kMParams_480[0]},
    {"floodCount", "number", 6, &kMParams_480[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_480[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_481[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_481[] = {
    {"astarGridPath", "list number", 8, &kMParams_481[0]},
    {"floodCount", "number", 6, &kMParams_481[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_481[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_482[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_482[] = {
    {"astarGridPath", "list number", 8, &kMParams_482[0]},
    {"floodCount", "number", 6, &kMParams_482[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_482[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_483[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_483[] = {
    {"astarGridPath", "list number", 8, &kMParams_483[0]},
    {"floodCount", "number", 6, &kMParams_483[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_483[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_484[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_484[] = {
    {"astarGridPath", "list number", 8, &kMParams_484[0]},
    {"floodCount", "number", 6, &kMParams_484[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_484[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_485[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_485[] = {
    {"astarGridPath", "list number", 8, &kMParams_485[0]},
    {"floodCount", "number", 6, &kMParams_485[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_485[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_486[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_486[] = {
    {"astarGridPath", "list number", 8, &kMParams_486[0]},
    {"floodCount", "number", 6, &kMParams_486[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_486[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_487[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_487[] = {
    {"astarGridPath", "list number", 8, &kMParams_487[0]},
    {"floodCount", "number", 6, &kMParams_487[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_487[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_488[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_488[] = {
    {"astarGridPath", "list number", 8, &kMParams_488[0]},
    {"floodCount", "number", 6, &kMParams_488[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_488[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_489[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_489[] = {
    {"astarGridPath", "list number", 8, &kMParams_489[0]},
    {"floodCount", "number", 6, &kMParams_489[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_489[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_490[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_490[] = {
    {"astarGridPath", "list number", 8, &kMParams_490[0]},
    {"floodCount", "number", 6, &kMParams_490[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_490[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_491[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_491[] = {
    {"astarGridPath", "list number", 8, &kMParams_491[0]},
    {"floodCount", "number", 6, &kMParams_491[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_491[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_492[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_492[] = {
    {"astarGridPath", "list number", 8, &kMParams_492[0]},
    {"floodCount", "number", 6, &kMParams_492[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_492[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_493[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_493[] = {
    {"astarGridPath", "list number", 8, &kMParams_493[0]},
    {"floodCount", "number", 6, &kMParams_493[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_493[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_494[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_494[] = {
    {"astarGridPath", "list number", 8, &kMParams_494[0]},
    {"floodCount", "number", 6, &kMParams_494[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_494[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_495[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_495[] = {
    {"astarGridPath", "list number", 8, &kMParams_495[0]},
    {"floodCount", "number", 6, &kMParams_495[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_495[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_496[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_496[] = {
    {"astarGridPath", "list number", 8, &kMParams_496[0]},
    {"floodCount", "number", 6, &kMParams_496[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_496[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_497[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_497[] = {
    {"astarGridPath", "list number", 8, &kMParams_497[0]},
    {"floodCount", "number", 6, &kMParams_497[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_497[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_498[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_498[] = {
    {"astarGridPath", "list number", 8, &kMParams_498[0]},
    {"floodCount", "number", 6, &kMParams_498[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_498[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_499[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_499[] = {
    {"astarGridPath", "list number", 8, &kMParams_499[0]},
    {"floodCount", "number", 6, &kMParams_499[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_499[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_500[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_500[] = {
    {"astarGridPath", "list number", 8, &kMParams_500[0]},
    {"floodCount", "number", 6, &kMParams_500[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_500[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_501[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_501[] = {
    {"astarGridPath", "list number", 8, &kMParams_501[0]},
    {"floodCount", "number", 6, &kMParams_501[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_501[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_502[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_502[] = {
    {"astarGridPath", "list number", 8, &kMParams_502[0]},
    {"floodCount", "number", 6, &kMParams_502[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_502[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_503[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_503[] = {
    {"astarGridPath", "list number", 8, &kMParams_503[0]},
    {"floodCount", "number", 6, &kMParams_503[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_503[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_504[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_504[] = {
    {"astarGridPath", "list number", 8, &kMParams_504[0]},
    {"floodCount", "number", 6, &kMParams_504[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_504[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_505[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_505[] = {
    {"astarGridPath", "list number", 8, &kMParams_505[0]},
    {"floodCount", "number", 6, &kMParams_505[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_505[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_506[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_506[] = {
    {"astarGridPath", "list number", 8, &kMParams_506[0]},
    {"floodCount", "number", 6, &kMParams_506[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_506[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_507[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_507[] = {
    {"astarGridPath", "list number", 8, &kMParams_507[0]},
    {"floodCount", "number", 6, &kMParams_507[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_507[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_508[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_508[] = {
    {"astarGridPath", "list number", 8, &kMParams_508[0]},
    {"floodCount", "number", 6, &kMParams_508[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_508[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_509[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_509[] = {
    {"astarGridPath", "list number", 8, &kMParams_509[0]},
    {"floodCount", "number", 6, &kMParams_509[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_509[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_510[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_510[] = {
    {"astarGridPath", "list number", 8, &kMParams_510[0]},
    {"floodCount", "number", 6, &kMParams_510[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_510[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_511[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_511[] = {
    {"astarGridPath", "list number", 8, &kMParams_511[0]},
    {"floodCount", "number", 6, &kMParams_511[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_511[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_512[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_512[] = {
    {"astarGridPath", "list number", 8, &kMParams_512[0]},
    {"floodCount", "number", 6, &kMParams_512[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_512[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_513[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_513[] = {
    {"astarGridPath", "list number", 8, &kMParams_513[0]},
    {"floodCount", "number", 6, &kMParams_513[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_513[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_514[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_514[] = {
    {"astarGridPath", "list number", 8, &kMParams_514[0]},
    {"floodCount", "number", 6, &kMParams_514[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_514[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_515[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_515[] = {
    {"astarGridPath", "list number", 8, &kMParams_515[0]},
    {"floodCount", "number", 6, &kMParams_515[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_515[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_516[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_516[] = {
    {"astarGridPath", "list number", 8, &kMParams_516[0]},
    {"floodCount", "number", 6, &kMParams_516[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_516[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_517[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_517[] = {
    {"astarGridPath", "list number", 8, &kMParams_517[0]},
    {"floodCount", "number", 6, &kMParams_517[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_517[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_518[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_518[] = {
    {"astarGridPath", "list number", 8, &kMParams_518[0]},
    {"floodCount", "number", 6, &kMParams_518[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_518[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_519[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_519[] = {
    {"astarGridPath", "list number", 8, &kMParams_519[0]},
    {"floodCount", "number", 6, &kMParams_519[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_519[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_520[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_520[] = {
    {"astarGridPath", "list number", 8, &kMParams_520[0]},
    {"floodCount", "number", 6, &kMParams_520[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_520[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_521[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_521[] = {
    {"astarGridPath", "list number", 8, &kMParams_521[0]},
    {"floodCount", "number", 6, &kMParams_521[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_521[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_522[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_522[] = {
    {"astarGridPath", "list number", 8, &kMParams_522[0]},
    {"floodCount", "number", 6, &kMParams_522[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_522[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_523[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_523[] = {
    {"astarGridPath", "list number", 8, &kMParams_523[0]},
    {"floodCount", "number", 6, &kMParams_523[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_523[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_524[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_524[] = {
    {"astarGridPath", "list number", 8, &kMParams_524[0]},
    {"floodCount", "number", 6, &kMParams_524[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_524[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_525[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_525[] = {
    {"astarGridPath", "list number", 8, &kMParams_525[0]},
    {"floodCount", "number", 6, &kMParams_525[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_525[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_526[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_526[] = {
    {"astarGridPath", "list number", 8, &kMParams_526[0]},
    {"floodCount", "number", 6, &kMParams_526[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_526[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_527[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_527[] = {
    {"astarGridPath", "list number", 8, &kMParams_527[0]},
    {"floodCount", "number", 6, &kMParams_527[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_527[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_528[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_528[] = {
    {"astarGridPath", "list number", 8, &kMParams_528[0]},
    {"floodCount", "number", 6, &kMParams_528[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_528[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_529[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_529[] = {
    {"astarGridPath", "list number", 8, &kMParams_529[0]},
    {"floodCount", "number", 6, &kMParams_529[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_529[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_530[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_530[] = {
    {"astarGridPath", "list number", 8, &kMParams_530[0]},
    {"floodCount", "number", 6, &kMParams_530[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_530[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_531[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_531[] = {
    {"astarGridPath", "list number", 8, &kMParams_531[0]},
    {"floodCount", "number", 6, &kMParams_531[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_531[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_532[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_532[] = {
    {"astarGridPath", "list number", 8, &kMParams_532[0]},
    {"floodCount", "number", 6, &kMParams_532[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_532[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_533[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_533[] = {
    {"astarGridPath", "list number", 8, &kMParams_533[0]},
    {"floodCount", "number", 6, &kMParams_533[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_533[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_534[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_534[] = {
    {"astarGridPath", "list number", 8, &kMParams_534[0]},
    {"floodCount", "number", 6, &kMParams_534[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_534[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_535[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_535[] = {
    {"astarGridPath", "list number", 8, &kMParams_535[0]},
    {"floodCount", "number", 6, &kMParams_535[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_535[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_536[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_536[] = {
    {"astarGridPath", "list number", 8, &kMParams_536[0]},
    {"floodCount", "number", 6, &kMParams_536[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_536[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_537[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_537[] = {
    {"astarGridPath", "list number", 8, &kMParams_537[0]},
    {"floodCount", "number", 6, &kMParams_537[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_537[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_538[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_538[] = {
    {"astarGridPath", "list number", 8, &kMParams_538[0]},
    {"floodCount", "number", 6, &kMParams_538[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_538[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_539[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_539[] = {
    {"astarGridPath", "list number", 8, &kMParams_539[0]},
    {"floodCount", "number", 6, &kMParams_539[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_539[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_540[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_540[] = {
    {"astarGridPath", "list number", 8, &kMParams_540[0]},
    {"floodCount", "number", 6, &kMParams_540[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_540[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_541[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_541[] = {
    {"astarGridPath", "list number", 8, &kMParams_541[0]},
    {"floodCount", "number", 6, &kMParams_541[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_541[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_542[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_542[] = {
    {"astarGridPath", "list number", 8, &kMParams_542[0]},
    {"floodCount", "number", 6, &kMParams_542[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_542[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_543[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_543[] = {
    {"astarGridPath", "list number", 8, &kMParams_543[0]},
    {"floodCount", "number", 6, &kMParams_543[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_543[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_544[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_544[] = {
    {"astarGridPath", "list number", 8, &kMParams_544[0]},
    {"floodCount", "number", 6, &kMParams_544[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_544[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_545[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_545[] = {
    {"astarGridPath", "list number", 8, &kMParams_545[0]},
    {"floodCount", "number", 6, &kMParams_545[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_545[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_546[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_546[] = {
    {"astarGridPath", "list number", 8, &kMParams_546[0]},
    {"floodCount", "number", 6, &kMParams_546[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_546[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_547[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_547[] = {
    {"astarGridPath", "list number", 8, &kMParams_547[0]},
    {"floodCount", "number", 6, &kMParams_547[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_547[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_548[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_548[] = {
    {"astarGridPath", "list number", 8, &kMParams_548[0]},
    {"floodCount", "number", 6, &kMParams_548[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_548[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_549[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_549[] = {
    {"astarGridPath", "list number", 8, &kMParams_549[0]},
    {"floodCount", "number", 6, &kMParams_549[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_549[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_550[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_550[] = {
    {"astarGridPath", "list number", 8, &kMParams_550[0]},
    {"floodCount", "number", 6, &kMParams_550[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_550[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_551[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_551[] = {
    {"astarGridPath", "list number", 8, &kMParams_551[0]},
    {"floodCount", "number", 6, &kMParams_551[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_551[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_552[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_552[] = {
    {"astarGridPath", "list number", 8, &kMParams_552[0]},
    {"floodCount", "number", 6, &kMParams_552[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_552[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_553[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_553[] = {
    {"astarGridPath", "list number", 8, &kMParams_553[0]},
    {"floodCount", "number", 6, &kMParams_553[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_553[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_554[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_554[] = {
    {"astarGridPath", "list number", 8, &kMParams_554[0]},
    {"floodCount", "number", 6, &kMParams_554[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_554[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_555[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_555[] = {
    {"astarGridPath", "list number", 8, &kMParams_555[0]},
    {"floodCount", "number", 6, &kMParams_555[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_555[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_556[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_556[] = {
    {"astarGridPath", "list number", 8, &kMParams_556[0]},
    {"floodCount", "number", 6, &kMParams_556[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_556[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_557[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_557[] = {
    {"astarGridPath", "list number", 8, &kMParams_557[0]},
    {"floodCount", "number", 6, &kMParams_557[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_557[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_558[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_558[] = {
    {"astarGridPath", "list number", 8, &kMParams_558[0]},
    {"floodCount", "number", 6, &kMParams_558[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_558[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_559[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_559[] = {
    {"astarGridPath", "list number", 8, &kMParams_559[0]},
    {"floodCount", "number", 6, &kMParams_559[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_559[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_560[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_560[] = {
    {"astarGridPath", "list number", 8, &kMParams_560[0]},
    {"floodCount", "number", 6, &kMParams_560[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_560[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_561[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_561[] = {
    {"astarGridPath", "list number", 8, &kMParams_561[0]},
    {"floodCount", "number", 6, &kMParams_561[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_561[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_562[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_562[] = {
    {"astarGridPath", "list number", 8, &kMParams_562[0]},
    {"floodCount", "number", 6, &kMParams_562[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_562[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_563[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_563[] = {
    {"astarGridPath", "list number", 8, &kMParams_563[0]},
    {"floodCount", "number", 6, &kMParams_563[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_563[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_564[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_564[] = {
    {"astarGridPath", "list number", 8, &kMParams_564[0]},
    {"floodCount", "number", 6, &kMParams_564[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_564[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_565[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_565[] = {
    {"astarGridPath", "list number", 8, &kMParams_565[0]},
    {"floodCount", "number", 6, &kMParams_565[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_565[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_566[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_566[] = {
    {"astarGridPath", "list number", 8, &kMParams_566[0]},
    {"floodCount", "number", 6, &kMParams_566[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_566[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_567[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_567[] = {
    {"astarGridPath", "list number", 8, &kMParams_567[0]},
    {"floodCount", "number", 6, &kMParams_567[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_567[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_568[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_568[] = {
    {"astarGridPath", "list number", 8, &kMParams_568[0]},
    {"floodCount", "number", 6, &kMParams_568[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_568[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_569[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_569[] = {
    {"astarGridPath", "list number", 8, &kMParams_569[0]},
    {"floodCount", "number", 6, &kMParams_569[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_569[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_570[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_570[] = {
    {"astarGridPath", "list number", 8, &kMParams_570[0]},
    {"floodCount", "number", 6, &kMParams_570[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_570[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_571[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_571[] = {
    {"astarGridPath", "list number", 8, &kMParams_571[0]},
    {"floodCount", "number", 6, &kMParams_571[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_571[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_572[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_572[] = {
    {"astarGridPath", "list number", 8, &kMParams_572[0]},
    {"floodCount", "number", 6, &kMParams_572[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_572[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_573[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_573[] = {
    {"astarGridPath", "list number", 8, &kMParams_573[0]},
    {"floodCount", "number", 6, &kMParams_573[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_573[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_574[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_574[] = {
    {"astarGridPath", "list number", 8, &kMParams_574[0]},
    {"floodCount", "number", 6, &kMParams_574[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_574[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_575[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_575[] = {
    {"astarGridPath", "list number", 8, &kMParams_575[0]},
    {"floodCount", "number", 6, &kMParams_575[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_575[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_576[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_576[] = {
    {"astarGridPath", "list number", 8, &kMParams_576[0]},
    {"floodCount", "number", 6, &kMParams_576[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_576[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_577[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_577[] = {
    {"astarGridPath", "list number", 8, &kMParams_577[0]},
    {"floodCount", "number", 6, &kMParams_577[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_577[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_578[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_578[] = {
    {"astarGridPath", "list number", 8, &kMParams_578[0]},
    {"floodCount", "number", 6, &kMParams_578[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_578[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_579[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_579[] = {
    {"astarGridPath", "list number", 8, &kMParams_579[0]},
    {"floodCount", "number", 6, &kMParams_579[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_579[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_580[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_580[] = {
    {"astarGridPath", "list number", 8, &kMParams_580[0]},
    {"floodCount", "number", 6, &kMParams_580[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_580[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_581[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_581[] = {
    {"astarGridPath", "list number", 8, &kMParams_581[0]},
    {"floodCount", "number", 6, &kMParams_581[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_581[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_582[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_582[] = {
    {"astarGridPath", "list number", 8, &kMParams_582[0]},
    {"floodCount", "number", 6, &kMParams_582[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_582[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_583[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_583[] = {
    {"astarGridPath", "list number", 8, &kMParams_583[0]},
    {"floodCount", "number", 6, &kMParams_583[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_583[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_584[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_584[] = {
    {"astarGridPath", "list number", 8, &kMParams_584[0]},
    {"floodCount", "number", 6, &kMParams_584[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_584[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_585[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_585[] = {
    {"astarGridPath", "list number", 8, &kMParams_585[0]},
    {"floodCount", "number", 6, &kMParams_585[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_585[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_586[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_586[] = {
    {"astarGridPath", "list number", 8, &kMParams_586[0]},
    {"floodCount", "number", 6, &kMParams_586[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_586[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_587[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_587[] = {
    {"astarGridPath", "list number", 8, &kMParams_587[0]},
    {"floodCount", "number", 6, &kMParams_587[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_587[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_588[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_588[] = {
    {"astarGridPath", "list number", 8, &kMParams_588[0]},
    {"floodCount", "number", 6, &kMParams_588[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_588[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_589[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_589[] = {
    {"astarGridPath", "list number", 8, &kMParams_589[0]},
    {"floodCount", "number", 6, &kMParams_589[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_589[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_590[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_590[] = {
    {"astarGridPath", "list number", 8, &kMParams_590[0]},
    {"floodCount", "number", 6, &kMParams_590[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_590[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_591[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_591[] = {
    {"astarGridPath", "list number", 8, &kMParams_591[0]},
    {"floodCount", "number", 6, &kMParams_591[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_591[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_592[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_592[] = {
    {"astarGridPath", "list number", 8, &kMParams_592[0]},
    {"floodCount", "number", 6, &kMParams_592[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_592[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_593[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_593[] = {
    {"astarGridPath", "list number", 8, &kMParams_593[0]},
    {"floodCount", "number", 6, &kMParams_593[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_593[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_594[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_594[] = {
    {"astarGridPath", "list number", 8, &kMParams_594[0]},
    {"floodCount", "number", 6, &kMParams_594[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_594[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_595[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_595[] = {
    {"astarGridPath", "list number", 8, &kMParams_595[0]},
    {"floodCount", "number", 6, &kMParams_595[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_595[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_596[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_596[] = {
    {"astarGridPath", "list number", 8, &kMParams_596[0]},
    {"floodCount", "number", 6, &kMParams_596[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_596[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_597[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_597[] = {
    {"astarGridPath", "list number", 8, &kMParams_597[0]},
    {"floodCount", "number", 6, &kMParams_597[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_597[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_598[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_598[] = {
    {"astarGridPath", "list number", 8, &kMParams_598[0]},
    {"floodCount", "number", 6, &kMParams_598[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_598[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_599[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_599[] = {
    {"astarGridPath", "list number", 8, &kMParams_599[0]},
    {"floodCount", "number", 6, &kMParams_599[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_599[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_600[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_600[] = {
    {"astarGridPath", "list number", 8, &kMParams_600[0]},
    {"floodCount", "number", 6, &kMParams_600[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_600[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_601[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_601[] = {
    {"astarGridPath", "list number", 8, &kMParams_601[0]},
    {"floodCount", "number", 6, &kMParams_601[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_601[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_602[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_602[] = {
    {"astarGridPath", "list number", 8, &kMParams_602[0]},
    {"floodCount", "number", 6, &kMParams_602[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_602[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_603[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_603[] = {
    {"astarGridPath", "list number", 8, &kMParams_603[0]},
    {"floodCount", "number", 6, &kMParams_603[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_603[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_604[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_604[] = {
    {"astarGridPath", "list number", 8, &kMParams_604[0]},
    {"floodCount", "number", 6, &kMParams_604[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_604[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_605[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_605[] = {
    {"astarGridPath", "list number", 8, &kMParams_605[0]},
    {"floodCount", "number", 6, &kMParams_605[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_605[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_606[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_606[] = {
    {"astarGridPath", "list number", 8, &kMParams_606[0]},
    {"floodCount", "number", 6, &kMParams_606[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_606[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_607[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_607[] = {
    {"astarGridPath", "list number", 8, &kMParams_607[0]},
    {"floodCount", "number", 6, &kMParams_607[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_607[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_608[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_608[] = {
    {"astarGridPath", "list number", 8, &kMParams_608[0]},
    {"floodCount", "number", 6, &kMParams_608[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_608[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_609[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_609[] = {
    {"astarGridPath", "list number", 8, &kMParams_609[0]},
    {"floodCount", "number", 6, &kMParams_609[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_609[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_610[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_610[] = {
    {"astarGridPath", "list number", 8, &kMParams_610[0]},
    {"floodCount", "number", 6, &kMParams_610[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_610[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_611[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_611[] = {
    {"astarGridPath", "list number", 8, &kMParams_611[0]},
    {"floodCount", "number", 6, &kMParams_611[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_611[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_612[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_612[] = {
    {"astarGridPath", "list number", 8, &kMParams_612[0]},
    {"floodCount", "number", 6, &kMParams_612[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_612[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_613[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_613[] = {
    {"astarGridPath", "list number", 8, &kMParams_613[0]},
    {"floodCount", "number", 6, &kMParams_613[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_613[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_614[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_614[] = {
    {"astarGridPath", "list number", 8, &kMParams_614[0]},
    {"floodCount", "number", 6, &kMParams_614[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_614[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_615[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_615[] = {
    {"astarGridPath", "list number", 8, &kMParams_615[0]},
    {"floodCount", "number", 6, &kMParams_615[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_615[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_616[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_616[] = {
    {"astarGridPath", "list number", 8, &kMParams_616[0]},
    {"floodCount", "number", 6, &kMParams_616[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_616[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_617[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_617[] = {
    {"astarGridPath", "list number", 8, &kMParams_617[0]},
    {"floodCount", "number", 6, &kMParams_617[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_617[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_618[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_618[] = {
    {"astarGridPath", "list number", 8, &kMParams_618[0]},
    {"floodCount", "number", 6, &kMParams_618[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_618[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_619[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_619[] = {
    {"astarGridPath", "list number", 8, &kMParams_619[0]},
    {"floodCount", "number", 6, &kMParams_619[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_619[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_620[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_620[] = {
    {"astarGridPath", "list number", 8, &kMParams_620[0]},
    {"floodCount", "number", 6, &kMParams_620[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_620[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_621[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_621[] = {
    {"astarGridPath", "list number", 8, &kMParams_621[0]},
    {"floodCount", "number", 6, &kMParams_621[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_621[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_622[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_622[] = {
    {"astarGridPath", "list number", 8, &kMParams_622[0]},
    {"floodCount", "number", 6, &kMParams_622[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_622[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_623[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_623[] = {
    {"astarGridPath", "list number", 8, &kMParams_623[0]},
    {"floodCount", "number", 6, &kMParams_623[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_623[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_624[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_624[] = {
    {"astarGridPath", "list number", 8, &kMParams_624[0]},
    {"floodCount", "number", 6, &kMParams_624[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_624[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_625[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_625[] = {
    {"astarGridPath", "list number", 8, &kMParams_625[0]},
    {"floodCount", "number", 6, &kMParams_625[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_625[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_626[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_626[] = {
    {"astarGridPath", "list number", 8, &kMParams_626[0]},
    {"floodCount", "number", 6, &kMParams_626[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_626[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_627[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_627[] = {
    {"astarGridPath", "list number", 8, &kMParams_627[0]},
    {"floodCount", "number", 6, &kMParams_627[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_627[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_628[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_628[] = {
    {"astarGridPath", "list number", 8, &kMParams_628[0]},
    {"floodCount", "number", 6, &kMParams_628[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_628[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_629[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_629[] = {
    {"astarGridPath", "list number", 8, &kMParams_629[0]},
    {"floodCount", "number", 6, &kMParams_629[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_629[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_630[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_630[] = {
    {"astarGridPath", "list number", 8, &kMParams_630[0]},
    {"floodCount", "number", 6, &kMParams_630[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_630[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_631[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_631[] = {
    {"astarGridPath", "list number", 8, &kMParams_631[0]},
    {"floodCount", "number", 6, &kMParams_631[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_631[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_632[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_632[] = {
    {"astarGridPath", "list number", 8, &kMParams_632[0]},
    {"floodCount", "number", 6, &kMParams_632[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_632[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_633[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_633[] = {
    {"astarGridPath", "list number", 8, &kMParams_633[0]},
    {"floodCount", "number", 6, &kMParams_633[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_633[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_634[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_634[] = {
    {"astarGridPath", "list number", 8, &kMParams_634[0]},
    {"floodCount", "number", 6, &kMParams_634[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_634[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_635[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_635[] = {
    {"astarGridPath", "list number", 8, &kMParams_635[0]},
    {"floodCount", "number", 6, &kMParams_635[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_635[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_636[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_636[] = {
    {"astarGridPath", "list number", 8, &kMParams_636[0]},
    {"floodCount", "number", 6, &kMParams_636[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_636[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_637[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_637[] = {
    {"astarGridPath", "list number", 8, &kMParams_637[0]},
    {"floodCount", "number", 6, &kMParams_637[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_637[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_638[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_638[] = {
    {"astarGridPath", "list number", 8, &kMParams_638[0]},
    {"floodCount", "number", 6, &kMParams_638[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_638[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_639[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_639[] = {
    {"astarGridPath", "list number", 8, &kMParams_639[0]},
    {"floodCount", "number", 6, &kMParams_639[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_639[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_640[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_640[] = {
    {"astarGridPath", "list number", 8, &kMParams_640[0]},
    {"floodCount", "number", 6, &kMParams_640[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_640[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_641[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_641[] = {
    {"astarGridPath", "list number", 8, &kMParams_641[0]},
    {"floodCount", "number", 6, &kMParams_641[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_641[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_642[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_642[] = {
    {"astarGridPath", "list number", 8, &kMParams_642[0]},
    {"floodCount", "number", 6, &kMParams_642[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_642[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_643[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_643[] = {
    {"astarGridPath", "list number", 8, &kMParams_643[0]},
    {"floodCount", "number", 6, &kMParams_643[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_643[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_644[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_644[] = {
    {"astarGridPath", "list number", 8, &kMParams_644[0]},
    {"floodCount", "number", 6, &kMParams_644[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_644[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_645[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_645[] = {
    {"astarGridPath", "list number", 8, &kMParams_645[0]},
    {"floodCount", "number", 6, &kMParams_645[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_645[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_646[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_646[] = {
    {"astarGridPath", "list number", 8, &kMParams_646[0]},
    {"floodCount", "number", 6, &kMParams_646[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_646[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_647[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_647[] = {
    {"astarGridPath", "list number", 8, &kMParams_647[0]},
    {"floodCount", "number", 6, &kMParams_647[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_647[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_648[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_648[] = {
    {"astarGridPath", "list number", 8, &kMParams_648[0]},
    {"floodCount", "number", 6, &kMParams_648[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_648[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_649[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_649[] = {
    {"astarGridPath", "list number", 8, &kMParams_649[0]},
    {"floodCount", "number", 6, &kMParams_649[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_649[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_650[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_650[] = {
    {"astarGridPath", "list number", 8, &kMParams_650[0]},
    {"floodCount", "number", 6, &kMParams_650[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_650[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_651[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_651[] = {
    {"astarGridPath", "list number", 8, &kMParams_651[0]},
    {"floodCount", "number", 6, &kMParams_651[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_651[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_652[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_652[] = {
    {"astarGridPath", "list number", 8, &kMParams_652[0]},
    {"floodCount", "number", 6, &kMParams_652[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_652[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_653[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_653[] = {
    {"astarGridPath", "list number", 8, &kMParams_653[0]},
    {"floodCount", "number", 6, &kMParams_653[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_653[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_654[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_654[] = {
    {"astarGridPath", "list number", 8, &kMParams_654[0]},
    {"floodCount", "number", 6, &kMParams_654[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_654[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_655[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_655[] = {
    {"astarGridPath", "list number", 8, &kMParams_655[0]},
    {"floodCount", "number", 6, &kMParams_655[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_655[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_656[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_656[] = {
    {"astarGridPath", "list number", 8, &kMParams_656[0]},
    {"floodCount", "number", 6, &kMParams_656[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_656[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_657[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_657[] = {
    {"astarGridPath", "list number", 8, &kMParams_657[0]},
    {"floodCount", "number", 6, &kMParams_657[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_657[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_658[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_658[] = {
    {"astarGridPath", "list number", 8, &kMParams_658[0]},
    {"floodCount", "number", 6, &kMParams_658[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_658[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_659[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_659[] = {
    {"astarGridPath", "list number", 8, &kMParams_659[0]},
    {"floodCount", "number", 6, &kMParams_659[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_659[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_660[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_660[] = {
    {"astarGridPath", "list number", 8, &kMParams_660[0]},
    {"floodCount", "number", 6, &kMParams_660[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_660[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_661[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_661[] = {
    {"astarGridPath", "list number", 8, &kMParams_661[0]},
    {"floodCount", "number", 6, &kMParams_661[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_661[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_662[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_662[] = {
    {"astarGridPath", "list number", 8, &kMParams_662[0]},
    {"floodCount", "number", 6, &kMParams_662[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_662[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_663[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_663[] = {
    {"astarGridPath", "list number", 8, &kMParams_663[0]},
    {"floodCount", "number", 6, &kMParams_663[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_663[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_664[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_664[] = {
    {"astarGridPath", "list number", 8, &kMParams_664[0]},
    {"floodCount", "number", 6, &kMParams_664[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_664[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_665[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_665[] = {
    {"astarGridPath", "list number", 8, &kMParams_665[0]},
    {"floodCount", "number", 6, &kMParams_665[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_665[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_666[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_666[] = {
    {"astarGridPath", "list number", 8, &kMParams_666[0]},
    {"floodCount", "number", 6, &kMParams_666[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_666[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_667[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_667[] = {
    {"astarGridPath", "list number", 8, &kMParams_667[0]},
    {"floodCount", "number", 6, &kMParams_667[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_667[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_668[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_668[] = {
    {"astarGridPath", "list number", 8, &kMParams_668[0]},
    {"floodCount", "number", 6, &kMParams_668[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_668[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_669[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_669[] = {
    {"astarGridPath", "list number", 8, &kMParams_669[0]},
    {"floodCount", "number", 6, &kMParams_669[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_669[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_670[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_670[] = {
    {"astarGridPath", "list number", 8, &kMParams_670[0]},
    {"floodCount", "number", 6, &kMParams_670[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_670[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_671[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_671[] = {
    {"astarGridPath", "list number", 8, &kMParams_671[0]},
    {"floodCount", "number", 6, &kMParams_671[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_671[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_672[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_672[] = {
    {"astarGridPath", "list number", 8, &kMParams_672[0]},
    {"floodCount", "number", 6, &kMParams_672[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_672[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_673[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_673[] = {
    {"astarGridPath", "list number", 8, &kMParams_673[0]},
    {"floodCount", "number", 6, &kMParams_673[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_673[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_674[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_674[] = {
    {"astarGridPath", "list number", 8, &kMParams_674[0]},
    {"floodCount", "number", 6, &kMParams_674[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_674[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_675[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_675[] = {
    {"astarGridPath", "list number", 8, &kMParams_675[0]},
    {"floodCount", "number", 6, &kMParams_675[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_675[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_676[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_676[] = {
    {"astarGridPath", "list number", 8, &kMParams_676[0]},
    {"floodCount", "number", 6, &kMParams_676[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_676[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_677[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_677[] = {
    {"astarGridPath", "list number", 8, &kMParams_677[0]},
    {"floodCount", "number", 6, &kMParams_677[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_677[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_678[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_678[] = {
    {"astarGridPath", "list number", 8, &kMParams_678[0]},
    {"floodCount", "number", 6, &kMParams_678[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_678[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_679[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_679[] = {
    {"astarGridPath", "list number", 8, &kMParams_679[0]},
    {"floodCount", "number", 6, &kMParams_679[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_679[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_680[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_680[] = {
    {"astarGridPath", "list number", 8, &kMParams_680[0]},
    {"floodCount", "number", 6, &kMParams_680[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_680[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_681[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_681[] = {
    {"astarGridPath", "list number", 8, &kMParams_681[0]},
    {"floodCount", "number", 6, &kMParams_681[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_681[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_682[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_682[] = {
    {"astarGridPath", "list number", 8, &kMParams_682[0]},
    {"floodCount", "number", 6, &kMParams_682[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_682[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_683[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_683[] = {
    {"astarGridPath", "list number", 8, &kMParams_683[0]},
    {"floodCount", "number", 6, &kMParams_683[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_683[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_684[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_684[] = {
    {"astarGridPath", "list number", 8, &kMParams_684[0]},
    {"floodCount", "number", 6, &kMParams_684[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_684[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_685[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_685[] = {
    {"astarGridPath", "list number", 8, &kMParams_685[0]},
    {"floodCount", "number", 6, &kMParams_685[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_685[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_686[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_686[] = {
    {"astarGridPath", "list number", 8, &kMParams_686[0]},
    {"floodCount", "number", 6, &kMParams_686[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_686[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_687[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_687[] = {
    {"astarGridPath", "list number", 8, &kMParams_687[0]},
    {"floodCount", "number", 6, &kMParams_687[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_687[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_688[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_688[] = {
    {"astarGridPath", "list number", 8, &kMParams_688[0]},
    {"floodCount", "number", 6, &kMParams_688[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_688[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_689[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_689[] = {
    {"astarGridPath", "list number", 8, &kMParams_689[0]},
    {"floodCount", "number", 6, &kMParams_689[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_689[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_690[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_690[] = {
    {"astarGridPath", "list number", 8, &kMParams_690[0]},
    {"floodCount", "number", 6, &kMParams_690[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_690[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_691[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_691[] = {
    {"astarGridPath", "list number", 8, &kMParams_691[0]},
    {"floodCount", "number", 6, &kMParams_691[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_691[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_692[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_692[] = {
    {"astarGridPath", "list number", 8, &kMParams_692[0]},
    {"floodCount", "number", 6, &kMParams_692[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_692[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_693[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_693[] = {
    {"astarGridPath", "list number", 8, &kMParams_693[0]},
    {"floodCount", "number", 6, &kMParams_693[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_693[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_694[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_694[] = {
    {"astarGridPath", "list number", 8, &kMParams_694[0]},
    {"floodCount", "number", 6, &kMParams_694[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_694[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_695[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_695[] = {
    {"astarGridPath", "list number", 8, &kMParams_695[0]},
    {"floodCount", "number", 6, &kMParams_695[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_695[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_696[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_696[] = {
    {"astarGridPath", "list number", 8, &kMParams_696[0]},
    {"floodCount", "number", 6, &kMParams_696[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_696[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_697[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_697[] = {
    {"astarGridPath", "list number", 8, &kMParams_697[0]},
    {"floodCount", "number", 6, &kMParams_697[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_697[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_698[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_698[] = {
    {"astarGridPath", "list number", 8, &kMParams_698[0]},
    {"floodCount", "number", 6, &kMParams_698[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_698[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_699[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_699[] = {
    {"astarGridPath", "list number", 8, &kMParams_699[0]},
    {"floodCount", "number", 6, &kMParams_699[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_699[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_700[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_700[] = {
    {"astarGridPath", "list number", 8, &kMParams_700[0]},
    {"floodCount", "number", 6, &kMParams_700[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_700[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_701[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_701[] = {
    {"astarGridPath", "list number", 8, &kMParams_701[0]},
    {"floodCount", "number", 6, &kMParams_701[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_701[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_702[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_702[] = {
    {"astarGridPath", "list number", 8, &kMParams_702[0]},
    {"floodCount", "number", 6, &kMParams_702[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_702[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_703[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_703[] = {
    {"astarGridPath", "list number", 8, &kMParams_703[0]},
    {"floodCount", "number", 6, &kMParams_703[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_703[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_704[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_704[] = {
    {"astarGridPath", "list number", 8, &kMParams_704[0]},
    {"floodCount", "number", 6, &kMParams_704[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_704[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_705[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_705[] = {
    {"astarGridPath", "list number", 8, &kMParams_705[0]},
    {"floodCount", "number", 6, &kMParams_705[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_705[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_706[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_706[] = {
    {"astarGridPath", "list number", 8, &kMParams_706[0]},
    {"floodCount", "number", 6, &kMParams_706[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_706[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_707[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_707[] = {
    {"astarGridPath", "list number", 8, &kMParams_707[0]},
    {"floodCount", "number", 6, &kMParams_707[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_707[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_708[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_708[] = {
    {"astarGridPath", "list number", 8, &kMParams_708[0]},
    {"floodCount", "number", 6, &kMParams_708[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_708[14]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_709[] = {
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"gx", "number"},
    {"gy", "number"},
    {"blockedAbove", "number"},
    {"grid", "list number"},
    {"w", "number"},
    {"h", "number"},
    {"sx", "number"},
    {"sy", "number"},
    {"blockedAbove", "number"},
    {"path", "list number"},
    {"w", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_709[] = {
    {"astarGridPath", "list number", 8, &kMParams_709[0]},
    {"floodCount", "number", 6, &kMParams_709[8]},
    {"simplifyGridPath", "list number", 2, &kMParams_709[14]},
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
    {"gameultra001", "gameultra001", kMFuncs_210, 3, "cx/complex_libs.hpp", false},
    {"gameultra002", "gameultra002", kMFuncs_211, 3, "cx/complex_libs.hpp", false},
    {"gameultra003", "gameultra003", kMFuncs_212, 3, "cx/complex_libs.hpp", false},
    {"gameultra004", "gameultra004", kMFuncs_213, 3, "cx/complex_libs.hpp", false},
    {"gameultra005", "gameultra005", kMFuncs_214, 3, "cx/complex_libs.hpp", false},
    {"gameultra006", "gameultra006", kMFuncs_215, 3, "cx/complex_libs.hpp", false},
    {"gameultra007", "gameultra007", kMFuncs_216, 3, "cx/complex_libs.hpp", false},
    {"gameultra008", "gameultra008", kMFuncs_217, 3, "cx/complex_libs.hpp", false},
    {"gameultra009", "gameultra009", kMFuncs_218, 3, "cx/complex_libs.hpp", false},
    {"gameultra010", "gameultra010", kMFuncs_219, 3, "cx/complex_libs.hpp", false},
    {"gameultra011", "gameultra011", kMFuncs_220, 3, "cx/complex_libs.hpp", false},
    {"gameultra012", "gameultra012", kMFuncs_221, 3, "cx/complex_libs.hpp", false},
    {"gameultra013", "gameultra013", kMFuncs_222, 3, "cx/complex_libs.hpp", false},
    {"gameultra014", "gameultra014", kMFuncs_223, 3, "cx/complex_libs.hpp", false},
    {"gameultra015", "gameultra015", kMFuncs_224, 3, "cx/complex_libs.hpp", false},
    {"gameultra016", "gameultra016", kMFuncs_225, 3, "cx/complex_libs.hpp", false},
    {"gameultra017", "gameultra017", kMFuncs_226, 3, "cx/complex_libs.hpp", false},
    {"gameultra018", "gameultra018", kMFuncs_227, 3, "cx/complex_libs.hpp", false},
    {"gameultra019", "gameultra019", kMFuncs_228, 3, "cx/complex_libs.hpp", false},
    {"gameultra020", "gameultra020", kMFuncs_229, 3, "cx/complex_libs.hpp", false},
    {"gameultra021", "gameultra021", kMFuncs_230, 3, "cx/complex_libs.hpp", false},
    {"gameultra022", "gameultra022", kMFuncs_231, 3, "cx/complex_libs.hpp", false},
    {"gameultra023", "gameultra023", kMFuncs_232, 3, "cx/complex_libs.hpp", false},
    {"gameultra024", "gameultra024", kMFuncs_233, 3, "cx/complex_libs.hpp", false},
    {"gameultra025", "gameultra025", kMFuncs_234, 3, "cx/complex_libs.hpp", false},
    {"gameultra026", "gameultra026", kMFuncs_235, 3, "cx/complex_libs.hpp", false},
    {"gameultra027", "gameultra027", kMFuncs_236, 3, "cx/complex_libs.hpp", false},
    {"gameultra028", "gameultra028", kMFuncs_237, 3, "cx/complex_libs.hpp", false},
    {"gameultra029", "gameultra029", kMFuncs_238, 3, "cx/complex_libs.hpp", false},
    {"gameultra030", "gameultra030", kMFuncs_239, 3, "cx/complex_libs.hpp", false},
    {"gameultra031", "gameultra031", kMFuncs_240, 3, "cx/complex_libs.hpp", false},
    {"gameultra032", "gameultra032", kMFuncs_241, 3, "cx/complex_libs.hpp", false},
    {"gameultra033", "gameultra033", kMFuncs_242, 3, "cx/complex_libs.hpp", false},
    {"gameultra034", "gameultra034", kMFuncs_243, 3, "cx/complex_libs.hpp", false},
    {"gameultra035", "gameultra035", kMFuncs_244, 3, "cx/complex_libs.hpp", false},
    {"gameultra036", "gameultra036", kMFuncs_245, 3, "cx/complex_libs.hpp", false},
    {"gameultra037", "gameultra037", kMFuncs_246, 3, "cx/complex_libs.hpp", false},
    {"gameultra038", "gameultra038", kMFuncs_247, 3, "cx/complex_libs.hpp", false},
    {"gameultra039", "gameultra039", kMFuncs_248, 3, "cx/complex_libs.hpp", false},
    {"gameultra040", "gameultra040", kMFuncs_249, 3, "cx/complex_libs.hpp", false},
    {"gameultra041", "gameultra041", kMFuncs_250, 3, "cx/complex_libs.hpp", false},
    {"gameultra042", "gameultra042", kMFuncs_251, 3, "cx/complex_libs.hpp", false},
    {"gameultra043", "gameultra043", kMFuncs_252, 3, "cx/complex_libs.hpp", false},
    {"gameultra044", "gameultra044", kMFuncs_253, 3, "cx/complex_libs.hpp", false},
    {"gameultra045", "gameultra045", kMFuncs_254, 3, "cx/complex_libs.hpp", false},
    {"gameultra046", "gameultra046", kMFuncs_255, 3, "cx/complex_libs.hpp", false},
    {"gameultra047", "gameultra047", kMFuncs_256, 3, "cx/complex_libs.hpp", false},
    {"gameultra048", "gameultra048", kMFuncs_257, 3, "cx/complex_libs.hpp", false},
    {"gameultra049", "gameultra049", kMFuncs_258, 3, "cx/complex_libs.hpp", false},
    {"gameultra050", "gameultra050", kMFuncs_259, 3, "cx/complex_libs.hpp", false},
    {"gameultra051", "gameultra051", kMFuncs_260, 3, "cx/complex_libs.hpp", false},
    {"gameultra052", "gameultra052", kMFuncs_261, 3, "cx/complex_libs.hpp", false},
    {"gameultra053", "gameultra053", kMFuncs_262, 3, "cx/complex_libs.hpp", false},
    {"gameultra054", "gameultra054", kMFuncs_263, 3, "cx/complex_libs.hpp", false},
    {"gameultra055", "gameultra055", kMFuncs_264, 3, "cx/complex_libs.hpp", false},
    {"gameultra056", "gameultra056", kMFuncs_265, 3, "cx/complex_libs.hpp", false},
    {"gameultra057", "gameultra057", kMFuncs_266, 3, "cx/complex_libs.hpp", false},
    {"gameultra058", "gameultra058", kMFuncs_267, 3, "cx/complex_libs.hpp", false},
    {"gameultra059", "gameultra059", kMFuncs_268, 3, "cx/complex_libs.hpp", false},
    {"gameultra060", "gameultra060", kMFuncs_269, 3, "cx/complex_libs.hpp", false},
    {"gameultra061", "gameultra061", kMFuncs_270, 3, "cx/complex_libs.hpp", false},
    {"gameultra062", "gameultra062", kMFuncs_271, 3, "cx/complex_libs.hpp", false},
    {"gameultra063", "gameultra063", kMFuncs_272, 3, "cx/complex_libs.hpp", false},
    {"gameultra064", "gameultra064", kMFuncs_273, 3, "cx/complex_libs.hpp", false},
    {"gameultra065", "gameultra065", kMFuncs_274, 3, "cx/complex_libs.hpp", false},
    {"gameultra066", "gameultra066", kMFuncs_275, 3, "cx/complex_libs.hpp", false},
    {"gameultra067", "gameultra067", kMFuncs_276, 3, "cx/complex_libs.hpp", false},
    {"gameultra068", "gameultra068", kMFuncs_277, 3, "cx/complex_libs.hpp", false},
    {"gameultra069", "gameultra069", kMFuncs_278, 3, "cx/complex_libs.hpp", false},
    {"gameultra070", "gameultra070", kMFuncs_279, 3, "cx/complex_libs.hpp", false},
    {"gameultra071", "gameultra071", kMFuncs_280, 3, "cx/complex_libs.hpp", false},
    {"gameultra072", "gameultra072", kMFuncs_281, 3, "cx/complex_libs.hpp", false},
    {"gameultra073", "gameultra073", kMFuncs_282, 3, "cx/complex_libs.hpp", false},
    {"gameultra074", "gameultra074", kMFuncs_283, 3, "cx/complex_libs.hpp", false},
    {"gameultra075", "gameultra075", kMFuncs_284, 3, "cx/complex_libs.hpp", false},
    {"gameultra076", "gameultra076", kMFuncs_285, 3, "cx/complex_libs.hpp", false},
    {"gameultra077", "gameultra077", kMFuncs_286, 3, "cx/complex_libs.hpp", false},
    {"gameultra078", "gameultra078", kMFuncs_287, 3, "cx/complex_libs.hpp", false},
    {"gameultra079", "gameultra079", kMFuncs_288, 3, "cx/complex_libs.hpp", false},
    {"gameultra080", "gameultra080", kMFuncs_289, 3, "cx/complex_libs.hpp", false},
    {"gameultra081", "gameultra081", kMFuncs_290, 3, "cx/complex_libs.hpp", false},
    {"gameultra082", "gameultra082", kMFuncs_291, 3, "cx/complex_libs.hpp", false},
    {"gameultra083", "gameultra083", kMFuncs_292, 3, "cx/complex_libs.hpp", false},
    {"gameultra084", "gameultra084", kMFuncs_293, 3, "cx/complex_libs.hpp", false},
    {"gameultra085", "gameultra085", kMFuncs_294, 3, "cx/complex_libs.hpp", false},
    {"gameultra086", "gameultra086", kMFuncs_295, 3, "cx/complex_libs.hpp", false},
    {"gameultra087", "gameultra087", kMFuncs_296, 3, "cx/complex_libs.hpp", false},
    {"gameultra088", "gameultra088", kMFuncs_297, 3, "cx/complex_libs.hpp", false},
    {"gameultra089", "gameultra089", kMFuncs_298, 3, "cx/complex_libs.hpp", false},
    {"gameultra090", "gameultra090", kMFuncs_299, 3, "cx/complex_libs.hpp", false},
    {"gameultra091", "gameultra091", kMFuncs_300, 3, "cx/complex_libs.hpp", false},
    {"gameultra092", "gameultra092", kMFuncs_301, 3, "cx/complex_libs.hpp", false},
    {"gameultra093", "gameultra093", kMFuncs_302, 3, "cx/complex_libs.hpp", false},
    {"gameultra094", "gameultra094", kMFuncs_303, 3, "cx/complex_libs.hpp", false},
    {"gameultra095", "gameultra095", kMFuncs_304, 3, "cx/complex_libs.hpp", false},
    {"gameultra096", "gameultra096", kMFuncs_305, 3, "cx/complex_libs.hpp", false},
    {"gameultra097", "gameultra097", kMFuncs_306, 3, "cx/complex_libs.hpp", false},
    {"gameultra098", "gameultra098", kMFuncs_307, 3, "cx/complex_libs.hpp", false},
    {"gameultra099", "gameultra099", kMFuncs_308, 3, "cx/complex_libs.hpp", false},
    {"gameultra100", "gameultra100", kMFuncs_309, 3, "cx/complex_libs.hpp", false},
    {"gameultra101", "gameultra101", kMFuncs_310, 3, "cx/complex_libs.hpp", false},
    {"gameultra102", "gameultra102", kMFuncs_311, 3, "cx/complex_libs.hpp", false},
    {"gameultra103", "gameultra103", kMFuncs_312, 3, "cx/complex_libs.hpp", false},
    {"gameultra104", "gameultra104", kMFuncs_313, 3, "cx/complex_libs.hpp", false},
    {"gameultra105", "gameultra105", kMFuncs_314, 3, "cx/complex_libs.hpp", false},
    {"gameultra106", "gameultra106", kMFuncs_315, 3, "cx/complex_libs.hpp", false},
    {"gameultra107", "gameultra107", kMFuncs_316, 3, "cx/complex_libs.hpp", false},
    {"gameultra108", "gameultra108", kMFuncs_317, 3, "cx/complex_libs.hpp", false},
    {"gameultra109", "gameultra109", kMFuncs_318, 3, "cx/complex_libs.hpp", false},
    {"gameultra110", "gameultra110", kMFuncs_319, 3, "cx/complex_libs.hpp", false},
    {"gameultra111", "gameultra111", kMFuncs_320, 3, "cx/complex_libs.hpp", false},
    {"gameultra112", "gameultra112", kMFuncs_321, 3, "cx/complex_libs.hpp", false},
    {"gameultra113", "gameultra113", kMFuncs_322, 3, "cx/complex_libs.hpp", false},
    {"gameultra114", "gameultra114", kMFuncs_323, 3, "cx/complex_libs.hpp", false},
    {"gameultra115", "gameultra115", kMFuncs_324, 3, "cx/complex_libs.hpp", false},
    {"gameultra116", "gameultra116", kMFuncs_325, 3, "cx/complex_libs.hpp", false},
    {"gameultra117", "gameultra117", kMFuncs_326, 3, "cx/complex_libs.hpp", false},
    {"gameultra118", "gameultra118", kMFuncs_327, 3, "cx/complex_libs.hpp", false},
    {"gameultra119", "gameultra119", kMFuncs_328, 3, "cx/complex_libs.hpp", false},
    {"gameultra120", "gameultra120", kMFuncs_329, 3, "cx/complex_libs.hpp", false},
    {"gameultra121", "gameultra121", kMFuncs_330, 3, "cx/complex_libs.hpp", false},
    {"gameultra122", "gameultra122", kMFuncs_331, 3, "cx/complex_libs.hpp", false},
    {"gameultra123", "gameultra123", kMFuncs_332, 3, "cx/complex_libs.hpp", false},
    {"gameultra124", "gameultra124", kMFuncs_333, 3, "cx/complex_libs.hpp", false},
    {"gameultra125", "gameultra125", kMFuncs_334, 3, "cx/complex_libs.hpp", false},
    {"gameultra126", "gameultra126", kMFuncs_335, 3, "cx/complex_libs.hpp", false},
    {"gameultra127", "gameultra127", kMFuncs_336, 3, "cx/complex_libs.hpp", false},
    {"gameultra128", "gameultra128", kMFuncs_337, 3, "cx/complex_libs.hpp", false},
    {"gameultra129", "gameultra129", kMFuncs_338, 3, "cx/complex_libs.hpp", false},
    {"gameultra130", "gameultra130", kMFuncs_339, 3, "cx/complex_libs.hpp", false},
    {"gameultra131", "gameultra131", kMFuncs_340, 3, "cx/complex_libs.hpp", false},
    {"gameultra132", "gameultra132", kMFuncs_341, 3, "cx/complex_libs.hpp", false},
    {"gameultra133", "gameultra133", kMFuncs_342, 3, "cx/complex_libs.hpp", false},
    {"gameultra134", "gameultra134", kMFuncs_343, 3, "cx/complex_libs.hpp", false},
    {"gameultra135", "gameultra135", kMFuncs_344, 3, "cx/complex_libs.hpp", false},
    {"gameultra136", "gameultra136", kMFuncs_345, 3, "cx/complex_libs.hpp", false},
    {"gameultra137", "gameultra137", kMFuncs_346, 3, "cx/complex_libs.hpp", false},
    {"gameultra138", "gameultra138", kMFuncs_347, 3, "cx/complex_libs.hpp", false},
    {"gameultra139", "gameultra139", kMFuncs_348, 3, "cx/complex_libs.hpp", false},
    {"gameultra140", "gameultra140", kMFuncs_349, 3, "cx/complex_libs.hpp", false},
    {"gameultra141", "gameultra141", kMFuncs_350, 3, "cx/complex_libs.hpp", false},
    {"gameultra142", "gameultra142", kMFuncs_351, 3, "cx/complex_libs.hpp", false},
    {"gameultra143", "gameultra143", kMFuncs_352, 3, "cx/complex_libs.hpp", false},
    {"gameultra144", "gameultra144", kMFuncs_353, 3, "cx/complex_libs.hpp", false},
    {"gameultra145", "gameultra145", kMFuncs_354, 3, "cx/complex_libs.hpp", false},
    {"gameultra146", "gameultra146", kMFuncs_355, 3, "cx/complex_libs.hpp", false},
    {"gameultra147", "gameultra147", kMFuncs_356, 3, "cx/complex_libs.hpp", false},
    {"gameultra148", "gameultra148", kMFuncs_357, 3, "cx/complex_libs.hpp", false},
    {"gameultra149", "gameultra149", kMFuncs_358, 3, "cx/complex_libs.hpp", false},
    {"gameultra150", "gameultra150", kMFuncs_359, 3, "cx/complex_libs.hpp", false},
    {"gameultra151", "gameultra151", kMFuncs_360, 3, "cx/complex_libs.hpp", false},
    {"gameultra152", "gameultra152", kMFuncs_361, 3, "cx/complex_libs.hpp", false},
    {"gameultra153", "gameultra153", kMFuncs_362, 3, "cx/complex_libs.hpp", false},
    {"gameultra154", "gameultra154", kMFuncs_363, 3, "cx/complex_libs.hpp", false},
    {"gameultra155", "gameultra155", kMFuncs_364, 3, "cx/complex_libs.hpp", false},
    {"gameultra156", "gameultra156", kMFuncs_365, 3, "cx/complex_libs.hpp", false},
    {"gameultra157", "gameultra157", kMFuncs_366, 3, "cx/complex_libs.hpp", false},
    {"gameultra158", "gameultra158", kMFuncs_367, 3, "cx/complex_libs.hpp", false},
    {"gameultra159", "gameultra159", kMFuncs_368, 3, "cx/complex_libs.hpp", false},
    {"gameultra160", "gameultra160", kMFuncs_369, 3, "cx/complex_libs.hpp", false},
    {"gameultra161", "gameultra161", kMFuncs_370, 3, "cx/complex_libs.hpp", false},
    {"gameultra162", "gameultra162", kMFuncs_371, 3, "cx/complex_libs.hpp", false},
    {"gameultra163", "gameultra163", kMFuncs_372, 3, "cx/complex_libs.hpp", false},
    {"gameultra164", "gameultra164", kMFuncs_373, 3, "cx/complex_libs.hpp", false},
    {"gameultra165", "gameultra165", kMFuncs_374, 3, "cx/complex_libs.hpp", false},
    {"gameultra166", "gameultra166", kMFuncs_375, 3, "cx/complex_libs.hpp", false},
    {"gameultra167", "gameultra167", kMFuncs_376, 3, "cx/complex_libs.hpp", false},
    {"gameultra168", "gameultra168", kMFuncs_377, 3, "cx/complex_libs.hpp", false},
    {"gameultra169", "gameultra169", kMFuncs_378, 3, "cx/complex_libs.hpp", false},
    {"gameultra170", "gameultra170", kMFuncs_379, 3, "cx/complex_libs.hpp", false},
    {"gameultra171", "gameultra171", kMFuncs_380, 3, "cx/complex_libs.hpp", false},
    {"gameultra172", "gameultra172", kMFuncs_381, 3, "cx/complex_libs.hpp", false},
    {"gameultra173", "gameultra173", kMFuncs_382, 3, "cx/complex_libs.hpp", false},
    {"gameultra174", "gameultra174", kMFuncs_383, 3, "cx/complex_libs.hpp", false},
    {"gameultra175", "gameultra175", kMFuncs_384, 3, "cx/complex_libs.hpp", false},
    {"gameultra176", "gameultra176", kMFuncs_385, 3, "cx/complex_libs.hpp", false},
    {"gameultra177", "gameultra177", kMFuncs_386, 3, "cx/complex_libs.hpp", false},
    {"gameultra178", "gameultra178", kMFuncs_387, 3, "cx/complex_libs.hpp", false},
    {"gameultra179", "gameultra179", kMFuncs_388, 3, "cx/complex_libs.hpp", false},
    {"gameultra180", "gameultra180", kMFuncs_389, 3, "cx/complex_libs.hpp", false},
    {"gameultra181", "gameultra181", kMFuncs_390, 3, "cx/complex_libs.hpp", false},
    {"gameultra182", "gameultra182", kMFuncs_391, 3, "cx/complex_libs.hpp", false},
    {"gameultra183", "gameultra183", kMFuncs_392, 3, "cx/complex_libs.hpp", false},
    {"gameultra184", "gameultra184", kMFuncs_393, 3, "cx/complex_libs.hpp", false},
    {"gameultra185", "gameultra185", kMFuncs_394, 3, "cx/complex_libs.hpp", false},
    {"gameultra186", "gameultra186", kMFuncs_395, 3, "cx/complex_libs.hpp", false},
    {"gameultra187", "gameultra187", kMFuncs_396, 3, "cx/complex_libs.hpp", false},
    {"gameultra188", "gameultra188", kMFuncs_397, 3, "cx/complex_libs.hpp", false},
    {"gameultra189", "gameultra189", kMFuncs_398, 3, "cx/complex_libs.hpp", false},
    {"gameultra190", "gameultra190", kMFuncs_399, 3, "cx/complex_libs.hpp", false},
    {"gameultra191", "gameultra191", kMFuncs_400, 3, "cx/complex_libs.hpp", false},
    {"gameultra192", "gameultra192", kMFuncs_401, 3, "cx/complex_libs.hpp", false},
    {"gameultra193", "gameultra193", kMFuncs_402, 3, "cx/complex_libs.hpp", false},
    {"gameultra194", "gameultra194", kMFuncs_403, 3, "cx/complex_libs.hpp", false},
    {"gameultra195", "gameultra195", kMFuncs_404, 3, "cx/complex_libs.hpp", false},
    {"gameultra196", "gameultra196", kMFuncs_405, 3, "cx/complex_libs.hpp", false},
    {"gameultra197", "gameultra197", kMFuncs_406, 3, "cx/complex_libs.hpp", false},
    {"gameultra198", "gameultra198", kMFuncs_407, 3, "cx/complex_libs.hpp", false},
    {"gameultra199", "gameultra199", kMFuncs_408, 3, "cx/complex_libs.hpp", false},
    {"gameultra200", "gameultra200", kMFuncs_409, 3, "cx/complex_libs.hpp", false},
    {"gameultra201", "gameultra201", kMFuncs_410, 3, "cx/complex_libs.hpp", false},
    {"gameultra202", "gameultra202", kMFuncs_411, 3, "cx/complex_libs.hpp", false},
    {"gameultra203", "gameultra203", kMFuncs_412, 3, "cx/complex_libs.hpp", false},
    {"gameultra204", "gameultra204", kMFuncs_413, 3, "cx/complex_libs.hpp", false},
    {"gameultra205", "gameultra205", kMFuncs_414, 3, "cx/complex_libs.hpp", false},
    {"gameultra206", "gameultra206", kMFuncs_415, 3, "cx/complex_libs.hpp", false},
    {"gameultra207", "gameultra207", kMFuncs_416, 3, "cx/complex_libs.hpp", false},
    {"gameultra208", "gameultra208", kMFuncs_417, 3, "cx/complex_libs.hpp", false},
    {"gameultra209", "gameultra209", kMFuncs_418, 3, "cx/complex_libs.hpp", false},
    {"gameultra210", "gameultra210", kMFuncs_419, 3, "cx/complex_libs.hpp", false},
    {"gameultra211", "gameultra211", kMFuncs_420, 3, "cx/complex_libs.hpp", false},
    {"gameultra212", "gameultra212", kMFuncs_421, 3, "cx/complex_libs.hpp", false},
    {"gameultra213", "gameultra213", kMFuncs_422, 3, "cx/complex_libs.hpp", false},
    {"gameultra214", "gameultra214", kMFuncs_423, 3, "cx/complex_libs.hpp", false},
    {"gameultra215", "gameultra215", kMFuncs_424, 3, "cx/complex_libs.hpp", false},
    {"gameultra216", "gameultra216", kMFuncs_425, 3, "cx/complex_libs.hpp", false},
    {"gameultra217", "gameultra217", kMFuncs_426, 3, "cx/complex_libs.hpp", false},
    {"gameultra218", "gameultra218", kMFuncs_427, 3, "cx/complex_libs.hpp", false},
    {"gameultra219", "gameultra219", kMFuncs_428, 3, "cx/complex_libs.hpp", false},
    {"gameultra220", "gameultra220", kMFuncs_429, 3, "cx/complex_libs.hpp", false},
    {"gameultra221", "gameultra221", kMFuncs_430, 3, "cx/complex_libs.hpp", false},
    {"gameultra222", "gameultra222", kMFuncs_431, 3, "cx/complex_libs.hpp", false},
    {"gameultra223", "gameultra223", kMFuncs_432, 3, "cx/complex_libs.hpp", false},
    {"gameultra224", "gameultra224", kMFuncs_433, 3, "cx/complex_libs.hpp", false},
    {"gameultra225", "gameultra225", kMFuncs_434, 3, "cx/complex_libs.hpp", false},
    {"gameultra226", "gameultra226", kMFuncs_435, 3, "cx/complex_libs.hpp", false},
    {"gameultra227", "gameultra227", kMFuncs_436, 3, "cx/complex_libs.hpp", false},
    {"gameultra228", "gameultra228", kMFuncs_437, 3, "cx/complex_libs.hpp", false},
    {"gameultra229", "gameultra229", kMFuncs_438, 3, "cx/complex_libs.hpp", false},
    {"gameultra230", "gameultra230", kMFuncs_439, 3, "cx/complex_libs.hpp", false},
    {"gameultra231", "gameultra231", kMFuncs_440, 3, "cx/complex_libs.hpp", false},
    {"gameultra232", "gameultra232", kMFuncs_441, 3, "cx/complex_libs.hpp", false},
    {"gameultra233", "gameultra233", kMFuncs_442, 3, "cx/complex_libs.hpp", false},
    {"gameultra234", "gameultra234", kMFuncs_443, 3, "cx/complex_libs.hpp", false},
    {"gameultra235", "gameultra235", kMFuncs_444, 3, "cx/complex_libs.hpp", false},
    {"gameultra236", "gameultra236", kMFuncs_445, 3, "cx/complex_libs.hpp", false},
    {"gameultra237", "gameultra237", kMFuncs_446, 3, "cx/complex_libs.hpp", false},
    {"gameultra238", "gameultra238", kMFuncs_447, 3, "cx/complex_libs.hpp", false},
    {"gameultra239", "gameultra239", kMFuncs_448, 3, "cx/complex_libs.hpp", false},
    {"gameultra240", "gameultra240", kMFuncs_449, 3, "cx/complex_libs.hpp", false},
    {"gameultra241", "gameultra241", kMFuncs_450, 3, "cx/complex_libs.hpp", false},
    {"gameultra242", "gameultra242", kMFuncs_451, 3, "cx/complex_libs.hpp", false},
    {"gameultra243", "gameultra243", kMFuncs_452, 3, "cx/complex_libs.hpp", false},
    {"gameultra244", "gameultra244", kMFuncs_453, 3, "cx/complex_libs.hpp", false},
    {"gameultra245", "gameultra245", kMFuncs_454, 3, "cx/complex_libs.hpp", false},
    {"gameultra246", "gameultra246", kMFuncs_455, 3, "cx/complex_libs.hpp", false},
    {"gameultra247", "gameultra247", kMFuncs_456, 3, "cx/complex_libs.hpp", false},
    {"gameultra248", "gameultra248", kMFuncs_457, 3, "cx/complex_libs.hpp", false},
    {"gameultra249", "gameultra249", kMFuncs_458, 3, "cx/complex_libs.hpp", false},
    {"gameultra250", "gameultra250", kMFuncs_459, 3, "cx/complex_libs.hpp", false},
    {"gameultra251", "gameultra251", kMFuncs_460, 3, "cx/complex_libs.hpp", false},
    {"gameultra252", "gameultra252", kMFuncs_461, 3, "cx/complex_libs.hpp", false},
    {"gameultra253", "gameultra253", kMFuncs_462, 3, "cx/complex_libs.hpp", false},
    {"gameultra254", "gameultra254", kMFuncs_463, 3, "cx/complex_libs.hpp", false},
    {"gameultra255", "gameultra255", kMFuncs_464, 3, "cx/complex_libs.hpp", false},
    {"gameultra256", "gameultra256", kMFuncs_465, 3, "cx/complex_libs.hpp", false},
    {"gameultra257", "gameultra257", kMFuncs_466, 3, "cx/complex_libs.hpp", false},
    {"gameultra258", "gameultra258", kMFuncs_467, 3, "cx/complex_libs.hpp", false},
    {"gameultra259", "gameultra259", kMFuncs_468, 3, "cx/complex_libs.hpp", false},
    {"gameultra260", "gameultra260", kMFuncs_469, 3, "cx/complex_libs.hpp", false},
    {"gameultra261", "gameultra261", kMFuncs_470, 3, "cx/complex_libs.hpp", false},
    {"gameultra262", "gameultra262", kMFuncs_471, 3, "cx/complex_libs.hpp", false},
    {"gameultra263", "gameultra263", kMFuncs_472, 3, "cx/complex_libs.hpp", false},
    {"gameultra264", "gameultra264", kMFuncs_473, 3, "cx/complex_libs.hpp", false},
    {"gameultra265", "gameultra265", kMFuncs_474, 3, "cx/complex_libs.hpp", false},
    {"gameultra266", "gameultra266", kMFuncs_475, 3, "cx/complex_libs.hpp", false},
    {"gameultra267", "gameultra267", kMFuncs_476, 3, "cx/complex_libs.hpp", false},
    {"gameultra268", "gameultra268", kMFuncs_477, 3, "cx/complex_libs.hpp", false},
    {"gameultra269", "gameultra269", kMFuncs_478, 3, "cx/complex_libs.hpp", false},
    {"gameultra270", "gameultra270", kMFuncs_479, 3, "cx/complex_libs.hpp", false},
    {"gameultra271", "gameultra271", kMFuncs_480, 3, "cx/complex_libs.hpp", false},
    {"gameultra272", "gameultra272", kMFuncs_481, 3, "cx/complex_libs.hpp", false},
    {"gameultra273", "gameultra273", kMFuncs_482, 3, "cx/complex_libs.hpp", false},
    {"gameultra274", "gameultra274", kMFuncs_483, 3, "cx/complex_libs.hpp", false},
    {"gameultra275", "gameultra275", kMFuncs_484, 3, "cx/complex_libs.hpp", false},
    {"gameultra276", "gameultra276", kMFuncs_485, 3, "cx/complex_libs.hpp", false},
    {"gameultra277", "gameultra277", kMFuncs_486, 3, "cx/complex_libs.hpp", false},
    {"gameultra278", "gameultra278", kMFuncs_487, 3, "cx/complex_libs.hpp", false},
    {"gameultra279", "gameultra279", kMFuncs_488, 3, "cx/complex_libs.hpp", false},
    {"gameultra280", "gameultra280", kMFuncs_489, 3, "cx/complex_libs.hpp", false},
    {"gameultra281", "gameultra281", kMFuncs_490, 3, "cx/complex_libs.hpp", false},
    {"gameultra282", "gameultra282", kMFuncs_491, 3, "cx/complex_libs.hpp", false},
    {"gameultra283", "gameultra283", kMFuncs_492, 3, "cx/complex_libs.hpp", false},
    {"gameultra284", "gameultra284", kMFuncs_493, 3, "cx/complex_libs.hpp", false},
    {"gameultra285", "gameultra285", kMFuncs_494, 3, "cx/complex_libs.hpp", false},
    {"gameultra286", "gameultra286", kMFuncs_495, 3, "cx/complex_libs.hpp", false},
    {"gameultra287", "gameultra287", kMFuncs_496, 3, "cx/complex_libs.hpp", false},
    {"gameultra288", "gameultra288", kMFuncs_497, 3, "cx/complex_libs.hpp", false},
    {"gameultra289", "gameultra289", kMFuncs_498, 3, "cx/complex_libs.hpp", false},
    {"gameultra290", "gameultra290", kMFuncs_499, 3, "cx/complex_libs.hpp", false},
    {"gameultra291", "gameultra291", kMFuncs_500, 3, "cx/complex_libs.hpp", false},
    {"gameultra292", "gameultra292", kMFuncs_501, 3, "cx/complex_libs.hpp", false},
    {"gameultra293", "gameultra293", kMFuncs_502, 3, "cx/complex_libs.hpp", false},
    {"gameultra294", "gameultra294", kMFuncs_503, 3, "cx/complex_libs.hpp", false},
    {"gameultra295", "gameultra295", kMFuncs_504, 3, "cx/complex_libs.hpp", false},
    {"gameultra296", "gameultra296", kMFuncs_505, 3, "cx/complex_libs.hpp", false},
    {"gameultra297", "gameultra297", kMFuncs_506, 3, "cx/complex_libs.hpp", false},
    {"gameultra298", "gameultra298", kMFuncs_507, 3, "cx/complex_libs.hpp", false},
    {"gameultra299", "gameultra299", kMFuncs_508, 3, "cx/complex_libs.hpp", false},
    {"gameultra300", "gameultra300", kMFuncs_509, 3, "cx/complex_libs.hpp", false},
    {"gameultra301", "gameultra301", kMFuncs_510, 3, "cx/complex_libs.hpp", false},
    {"gameultra302", "gameultra302", kMFuncs_511, 3, "cx/complex_libs.hpp", false},
    {"gameultra303", "gameultra303", kMFuncs_512, 3, "cx/complex_libs.hpp", false},
    {"gameultra304", "gameultra304", kMFuncs_513, 3, "cx/complex_libs.hpp", false},
    {"gameultra305", "gameultra305", kMFuncs_514, 3, "cx/complex_libs.hpp", false},
    {"gameultra306", "gameultra306", kMFuncs_515, 3, "cx/complex_libs.hpp", false},
    {"gameultra307", "gameultra307", kMFuncs_516, 3, "cx/complex_libs.hpp", false},
    {"gameultra308", "gameultra308", kMFuncs_517, 3, "cx/complex_libs.hpp", false},
    {"gameultra309", "gameultra309", kMFuncs_518, 3, "cx/complex_libs.hpp", false},
    {"gameultra310", "gameultra310", kMFuncs_519, 3, "cx/complex_libs.hpp", false},
    {"gameultra311", "gameultra311", kMFuncs_520, 3, "cx/complex_libs.hpp", false},
    {"gameultra312", "gameultra312", kMFuncs_521, 3, "cx/complex_libs.hpp", false},
    {"gameultra313", "gameultra313", kMFuncs_522, 3, "cx/complex_libs.hpp", false},
    {"gameultra314", "gameultra314", kMFuncs_523, 3, "cx/complex_libs.hpp", false},
    {"gameultra315", "gameultra315", kMFuncs_524, 3, "cx/complex_libs.hpp", false},
    {"gameultra316", "gameultra316", kMFuncs_525, 3, "cx/complex_libs.hpp", false},
    {"gameultra317", "gameultra317", kMFuncs_526, 3, "cx/complex_libs.hpp", false},
    {"gameultra318", "gameultra318", kMFuncs_527, 3, "cx/complex_libs.hpp", false},
    {"gameultra319", "gameultra319", kMFuncs_528, 3, "cx/complex_libs.hpp", false},
    {"gameultra320", "gameultra320", kMFuncs_529, 3, "cx/complex_libs.hpp", false},
    {"gameultra321", "gameultra321", kMFuncs_530, 3, "cx/complex_libs.hpp", false},
    {"gameultra322", "gameultra322", kMFuncs_531, 3, "cx/complex_libs.hpp", false},
    {"gameultra323", "gameultra323", kMFuncs_532, 3, "cx/complex_libs.hpp", false},
    {"gameultra324", "gameultra324", kMFuncs_533, 3, "cx/complex_libs.hpp", false},
    {"gameultra325", "gameultra325", kMFuncs_534, 3, "cx/complex_libs.hpp", false},
    {"gameultra326", "gameultra326", kMFuncs_535, 3, "cx/complex_libs.hpp", false},
    {"gameultra327", "gameultra327", kMFuncs_536, 3, "cx/complex_libs.hpp", false},
    {"gameultra328", "gameultra328", kMFuncs_537, 3, "cx/complex_libs.hpp", false},
    {"gameultra329", "gameultra329", kMFuncs_538, 3, "cx/complex_libs.hpp", false},
    {"gameultra330", "gameultra330", kMFuncs_539, 3, "cx/complex_libs.hpp", false},
    {"gameultra331", "gameultra331", kMFuncs_540, 3, "cx/complex_libs.hpp", false},
    {"gameultra332", "gameultra332", kMFuncs_541, 3, "cx/complex_libs.hpp", false},
    {"gameultra333", "gameultra333", kMFuncs_542, 3, "cx/complex_libs.hpp", false},
    {"gameultra334", "gameultra334", kMFuncs_543, 3, "cx/complex_libs.hpp", false},
    {"gameultra335", "gameultra335", kMFuncs_544, 3, "cx/complex_libs.hpp", false},
    {"gameultra336", "gameultra336", kMFuncs_545, 3, "cx/complex_libs.hpp", false},
    {"gameultra337", "gameultra337", kMFuncs_546, 3, "cx/complex_libs.hpp", false},
    {"gameultra338", "gameultra338", kMFuncs_547, 3, "cx/complex_libs.hpp", false},
    {"gameultra339", "gameultra339", kMFuncs_548, 3, "cx/complex_libs.hpp", false},
    {"gameultra340", "gameultra340", kMFuncs_549, 3, "cx/complex_libs.hpp", false},
    {"gameultra341", "gameultra341", kMFuncs_550, 3, "cx/complex_libs.hpp", false},
    {"gameultra342", "gameultra342", kMFuncs_551, 3, "cx/complex_libs.hpp", false},
    {"gameultra343", "gameultra343", kMFuncs_552, 3, "cx/complex_libs.hpp", false},
    {"gameultra344", "gameultra344", kMFuncs_553, 3, "cx/complex_libs.hpp", false},
    {"gameultra345", "gameultra345", kMFuncs_554, 3, "cx/complex_libs.hpp", false},
    {"gameultra346", "gameultra346", kMFuncs_555, 3, "cx/complex_libs.hpp", false},
    {"gameultra347", "gameultra347", kMFuncs_556, 3, "cx/complex_libs.hpp", false},
    {"gameultra348", "gameultra348", kMFuncs_557, 3, "cx/complex_libs.hpp", false},
    {"gameultra349", "gameultra349", kMFuncs_558, 3, "cx/complex_libs.hpp", false},
    {"gameultra350", "gameultra350", kMFuncs_559, 3, "cx/complex_libs.hpp", false},
    {"gameultra351", "gameultra351", kMFuncs_560, 3, "cx/complex_libs.hpp", false},
    {"gameultra352", "gameultra352", kMFuncs_561, 3, "cx/complex_libs.hpp", false},
    {"gameultra353", "gameultra353", kMFuncs_562, 3, "cx/complex_libs.hpp", false},
    {"gameultra354", "gameultra354", kMFuncs_563, 3, "cx/complex_libs.hpp", false},
    {"gameultra355", "gameultra355", kMFuncs_564, 3, "cx/complex_libs.hpp", false},
    {"gameultra356", "gameultra356", kMFuncs_565, 3, "cx/complex_libs.hpp", false},
    {"gameultra357", "gameultra357", kMFuncs_566, 3, "cx/complex_libs.hpp", false},
    {"gameultra358", "gameultra358", kMFuncs_567, 3, "cx/complex_libs.hpp", false},
    {"gameultra359", "gameultra359", kMFuncs_568, 3, "cx/complex_libs.hpp", false},
    {"gameultra360", "gameultra360", kMFuncs_569, 3, "cx/complex_libs.hpp", false},
    {"gameultra361", "gameultra361", kMFuncs_570, 3, "cx/complex_libs.hpp", false},
    {"gameultra362", "gameultra362", kMFuncs_571, 3, "cx/complex_libs.hpp", false},
    {"gameultra363", "gameultra363", kMFuncs_572, 3, "cx/complex_libs.hpp", false},
    {"gameultra364", "gameultra364", kMFuncs_573, 3, "cx/complex_libs.hpp", false},
    {"gameultra365", "gameultra365", kMFuncs_574, 3, "cx/complex_libs.hpp", false},
    {"gameultra366", "gameultra366", kMFuncs_575, 3, "cx/complex_libs.hpp", false},
    {"gameultra367", "gameultra367", kMFuncs_576, 3, "cx/complex_libs.hpp", false},
    {"gameultra368", "gameultra368", kMFuncs_577, 3, "cx/complex_libs.hpp", false},
    {"gameultra369", "gameultra369", kMFuncs_578, 3, "cx/complex_libs.hpp", false},
    {"gameultra370", "gameultra370", kMFuncs_579, 3, "cx/complex_libs.hpp", false},
    {"gameultra371", "gameultra371", kMFuncs_580, 3, "cx/complex_libs.hpp", false},
    {"gameultra372", "gameultra372", kMFuncs_581, 3, "cx/complex_libs.hpp", false},
    {"gameultra373", "gameultra373", kMFuncs_582, 3, "cx/complex_libs.hpp", false},
    {"gameultra374", "gameultra374", kMFuncs_583, 3, "cx/complex_libs.hpp", false},
    {"gameultra375", "gameultra375", kMFuncs_584, 3, "cx/complex_libs.hpp", false},
    {"gameultra376", "gameultra376", kMFuncs_585, 3, "cx/complex_libs.hpp", false},
    {"gameultra377", "gameultra377", kMFuncs_586, 3, "cx/complex_libs.hpp", false},
    {"gameultra378", "gameultra378", kMFuncs_587, 3, "cx/complex_libs.hpp", false},
    {"gameultra379", "gameultra379", kMFuncs_588, 3, "cx/complex_libs.hpp", false},
    {"gameultra380", "gameultra380", kMFuncs_589, 3, "cx/complex_libs.hpp", false},
    {"gameultra381", "gameultra381", kMFuncs_590, 3, "cx/complex_libs.hpp", false},
    {"gameultra382", "gameultra382", kMFuncs_591, 3, "cx/complex_libs.hpp", false},
    {"gameultra383", "gameultra383", kMFuncs_592, 3, "cx/complex_libs.hpp", false},
    {"gameultra384", "gameultra384", kMFuncs_593, 3, "cx/complex_libs.hpp", false},
    {"gameultra385", "gameultra385", kMFuncs_594, 3, "cx/complex_libs.hpp", false},
    {"gameultra386", "gameultra386", kMFuncs_595, 3, "cx/complex_libs.hpp", false},
    {"gameultra387", "gameultra387", kMFuncs_596, 3, "cx/complex_libs.hpp", false},
    {"gameultra388", "gameultra388", kMFuncs_597, 3, "cx/complex_libs.hpp", false},
    {"gameultra389", "gameultra389", kMFuncs_598, 3, "cx/complex_libs.hpp", false},
    {"gameultra390", "gameultra390", kMFuncs_599, 3, "cx/complex_libs.hpp", false},
    {"gameultra391", "gameultra391", kMFuncs_600, 3, "cx/complex_libs.hpp", false},
    {"gameultra392", "gameultra392", kMFuncs_601, 3, "cx/complex_libs.hpp", false},
    {"gameultra393", "gameultra393", kMFuncs_602, 3, "cx/complex_libs.hpp", false},
    {"gameultra394", "gameultra394", kMFuncs_603, 3, "cx/complex_libs.hpp", false},
    {"gameultra395", "gameultra395", kMFuncs_604, 3, "cx/complex_libs.hpp", false},
    {"gameultra396", "gameultra396", kMFuncs_605, 3, "cx/complex_libs.hpp", false},
    {"gameultra397", "gameultra397", kMFuncs_606, 3, "cx/complex_libs.hpp", false},
    {"gameultra398", "gameultra398", kMFuncs_607, 3, "cx/complex_libs.hpp", false},
    {"gameultra399", "gameultra399", kMFuncs_608, 3, "cx/complex_libs.hpp", false},
    {"gameultra400", "gameultra400", kMFuncs_609, 3, "cx/complex_libs.hpp", false},
    {"gameultra401", "gameultra401", kMFuncs_610, 3, "cx/complex_libs.hpp", false},
    {"gameultra402", "gameultra402", kMFuncs_611, 3, "cx/complex_libs.hpp", false},
    {"gameultra403", "gameultra403", kMFuncs_612, 3, "cx/complex_libs.hpp", false},
    {"gameultra404", "gameultra404", kMFuncs_613, 3, "cx/complex_libs.hpp", false},
    {"gameultra405", "gameultra405", kMFuncs_614, 3, "cx/complex_libs.hpp", false},
    {"gameultra406", "gameultra406", kMFuncs_615, 3, "cx/complex_libs.hpp", false},
    {"gameultra407", "gameultra407", kMFuncs_616, 3, "cx/complex_libs.hpp", false},
    {"gameultra408", "gameultra408", kMFuncs_617, 3, "cx/complex_libs.hpp", false},
    {"gameultra409", "gameultra409", kMFuncs_618, 3, "cx/complex_libs.hpp", false},
    {"gameultra410", "gameultra410", kMFuncs_619, 3, "cx/complex_libs.hpp", false},
    {"gameultra411", "gameultra411", kMFuncs_620, 3, "cx/complex_libs.hpp", false},
    {"gameultra412", "gameultra412", kMFuncs_621, 3, "cx/complex_libs.hpp", false},
    {"gameultra413", "gameultra413", kMFuncs_622, 3, "cx/complex_libs.hpp", false},
    {"gameultra414", "gameultra414", kMFuncs_623, 3, "cx/complex_libs.hpp", false},
    {"gameultra415", "gameultra415", kMFuncs_624, 3, "cx/complex_libs.hpp", false},
    {"gameultra416", "gameultra416", kMFuncs_625, 3, "cx/complex_libs.hpp", false},
    {"gameultra417", "gameultra417", kMFuncs_626, 3, "cx/complex_libs.hpp", false},
    {"gameultra418", "gameultra418", kMFuncs_627, 3, "cx/complex_libs.hpp", false},
    {"gameultra419", "gameultra419", kMFuncs_628, 3, "cx/complex_libs.hpp", false},
    {"gameultra420", "gameultra420", kMFuncs_629, 3, "cx/complex_libs.hpp", false},
    {"gameultra421", "gameultra421", kMFuncs_630, 3, "cx/complex_libs.hpp", false},
    {"gameultra422", "gameultra422", kMFuncs_631, 3, "cx/complex_libs.hpp", false},
    {"gameultra423", "gameultra423", kMFuncs_632, 3, "cx/complex_libs.hpp", false},
    {"gameultra424", "gameultra424", kMFuncs_633, 3, "cx/complex_libs.hpp", false},
    {"gameultra425", "gameultra425", kMFuncs_634, 3, "cx/complex_libs.hpp", false},
    {"gameultra426", "gameultra426", kMFuncs_635, 3, "cx/complex_libs.hpp", false},
    {"gameultra427", "gameultra427", kMFuncs_636, 3, "cx/complex_libs.hpp", false},
    {"gameultra428", "gameultra428", kMFuncs_637, 3, "cx/complex_libs.hpp", false},
    {"gameultra429", "gameultra429", kMFuncs_638, 3, "cx/complex_libs.hpp", false},
    {"gameultra430", "gameultra430", kMFuncs_639, 3, "cx/complex_libs.hpp", false},
    {"gameultra431", "gameultra431", kMFuncs_640, 3, "cx/complex_libs.hpp", false},
    {"gameultra432", "gameultra432", kMFuncs_641, 3, "cx/complex_libs.hpp", false},
    {"gameultra433", "gameultra433", kMFuncs_642, 3, "cx/complex_libs.hpp", false},
    {"gameultra434", "gameultra434", kMFuncs_643, 3, "cx/complex_libs.hpp", false},
    {"gameultra435", "gameultra435", kMFuncs_644, 3, "cx/complex_libs.hpp", false},
    {"gameultra436", "gameultra436", kMFuncs_645, 3, "cx/complex_libs.hpp", false},
    {"gameultra437", "gameultra437", kMFuncs_646, 3, "cx/complex_libs.hpp", false},
    {"gameultra438", "gameultra438", kMFuncs_647, 3, "cx/complex_libs.hpp", false},
    {"gameultra439", "gameultra439", kMFuncs_648, 3, "cx/complex_libs.hpp", false},
    {"gameultra440", "gameultra440", kMFuncs_649, 3, "cx/complex_libs.hpp", false},
    {"gameultra441", "gameultra441", kMFuncs_650, 3, "cx/complex_libs.hpp", false},
    {"gameultra442", "gameultra442", kMFuncs_651, 3, "cx/complex_libs.hpp", false},
    {"gameultra443", "gameultra443", kMFuncs_652, 3, "cx/complex_libs.hpp", false},
    {"gameultra444", "gameultra444", kMFuncs_653, 3, "cx/complex_libs.hpp", false},
    {"gameultra445", "gameultra445", kMFuncs_654, 3, "cx/complex_libs.hpp", false},
    {"gameultra446", "gameultra446", kMFuncs_655, 3, "cx/complex_libs.hpp", false},
    {"gameultra447", "gameultra447", kMFuncs_656, 3, "cx/complex_libs.hpp", false},
    {"gameultra448", "gameultra448", kMFuncs_657, 3, "cx/complex_libs.hpp", false},
    {"gameultra449", "gameultra449", kMFuncs_658, 3, "cx/complex_libs.hpp", false},
    {"gameultra450", "gameultra450", kMFuncs_659, 3, "cx/complex_libs.hpp", false},
    {"gameultra451", "gameultra451", kMFuncs_660, 3, "cx/complex_libs.hpp", false},
    {"gameultra452", "gameultra452", kMFuncs_661, 3, "cx/complex_libs.hpp", false},
    {"gameultra453", "gameultra453", kMFuncs_662, 3, "cx/complex_libs.hpp", false},
    {"gameultra454", "gameultra454", kMFuncs_663, 3, "cx/complex_libs.hpp", false},
    {"gameultra455", "gameultra455", kMFuncs_664, 3, "cx/complex_libs.hpp", false},
    {"gameultra456", "gameultra456", kMFuncs_665, 3, "cx/complex_libs.hpp", false},
    {"gameultra457", "gameultra457", kMFuncs_666, 3, "cx/complex_libs.hpp", false},
    {"gameultra458", "gameultra458", kMFuncs_667, 3, "cx/complex_libs.hpp", false},
    {"gameultra459", "gameultra459", kMFuncs_668, 3, "cx/complex_libs.hpp", false},
    {"gameultra460", "gameultra460", kMFuncs_669, 3, "cx/complex_libs.hpp", false},
    {"gameultra461", "gameultra461", kMFuncs_670, 3, "cx/complex_libs.hpp", false},
    {"gameultra462", "gameultra462", kMFuncs_671, 3, "cx/complex_libs.hpp", false},
    {"gameultra463", "gameultra463", kMFuncs_672, 3, "cx/complex_libs.hpp", false},
    {"gameultra464", "gameultra464", kMFuncs_673, 3, "cx/complex_libs.hpp", false},
    {"gameultra465", "gameultra465", kMFuncs_674, 3, "cx/complex_libs.hpp", false},
    {"gameultra466", "gameultra466", kMFuncs_675, 3, "cx/complex_libs.hpp", false},
    {"gameultra467", "gameultra467", kMFuncs_676, 3, "cx/complex_libs.hpp", false},
    {"gameultra468", "gameultra468", kMFuncs_677, 3, "cx/complex_libs.hpp", false},
    {"gameultra469", "gameultra469", kMFuncs_678, 3, "cx/complex_libs.hpp", false},
    {"gameultra470", "gameultra470", kMFuncs_679, 3, "cx/complex_libs.hpp", false},
    {"gameultra471", "gameultra471", kMFuncs_680, 3, "cx/complex_libs.hpp", false},
    {"gameultra472", "gameultra472", kMFuncs_681, 3, "cx/complex_libs.hpp", false},
    {"gameultra473", "gameultra473", kMFuncs_682, 3, "cx/complex_libs.hpp", false},
    {"gameultra474", "gameultra474", kMFuncs_683, 3, "cx/complex_libs.hpp", false},
    {"gameultra475", "gameultra475", kMFuncs_684, 3, "cx/complex_libs.hpp", false},
    {"gameultra476", "gameultra476", kMFuncs_685, 3, "cx/complex_libs.hpp", false},
    {"gameultra477", "gameultra477", kMFuncs_686, 3, "cx/complex_libs.hpp", false},
    {"gameultra478", "gameultra478", kMFuncs_687, 3, "cx/complex_libs.hpp", false},
    {"gameultra479", "gameultra479", kMFuncs_688, 3, "cx/complex_libs.hpp", false},
    {"gameultra480", "gameultra480", kMFuncs_689, 3, "cx/complex_libs.hpp", false},
    {"gameultra481", "gameultra481", kMFuncs_690, 3, "cx/complex_libs.hpp", false},
    {"gameultra482", "gameultra482", kMFuncs_691, 3, "cx/complex_libs.hpp", false},
    {"gameultra483", "gameultra483", kMFuncs_692, 3, "cx/complex_libs.hpp", false},
    {"gameultra484", "gameultra484", kMFuncs_693, 3, "cx/complex_libs.hpp", false},
    {"gameultra485", "gameultra485", kMFuncs_694, 3, "cx/complex_libs.hpp", false},
    {"gameultra486", "gameultra486", kMFuncs_695, 3, "cx/complex_libs.hpp", false},
    {"gameultra487", "gameultra487", kMFuncs_696, 3, "cx/complex_libs.hpp", false},
    {"gameultra488", "gameultra488", kMFuncs_697, 3, "cx/complex_libs.hpp", false},
    {"gameultra489", "gameultra489", kMFuncs_698, 3, "cx/complex_libs.hpp", false},
    {"gameultra490", "gameultra490", kMFuncs_699, 3, "cx/complex_libs.hpp", false},
    {"gameultra491", "gameultra491", kMFuncs_700, 3, "cx/complex_libs.hpp", false},
    {"gameultra492", "gameultra492", kMFuncs_701, 3, "cx/complex_libs.hpp", false},
    {"gameultra493", "gameultra493", kMFuncs_702, 3, "cx/complex_libs.hpp", false},
    {"gameultra494", "gameultra494", kMFuncs_703, 3, "cx/complex_libs.hpp", false},
    {"gameultra495", "gameultra495", kMFuncs_704, 3, "cx/complex_libs.hpp", false},
    {"gameultra496", "gameultra496", kMFuncs_705, 3, "cx/complex_libs.hpp", false},
    {"gameultra497", "gameultra497", kMFuncs_706, 3, "cx/complex_libs.hpp", false},
    {"gameultra498", "gameultra498", kMFuncs_707, 3, "cx/complex_libs.hpp", false},
    {"gameultra499", "gameultra499", kMFuncs_708, 3, "cx/complex_libs.hpp", false},
    {"gameultra500", "gameultra500", kMFuncs_709, 3, "cx/complex_libs.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kComplexModuleCount = 710;

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
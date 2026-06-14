# Bibliothèques complexes AFRILANG

**210 modules** — `std/c/{nom}`

## std/c/graphbfs

`import "std/c/graphbfs"` · `use graphbfs`

- `bfsDistances(adj list number, n number, start number) → list number`
- `bfsOrder(adj list number, n number, start number) → list number`
- `bfsReachable(adj list number, n number, start number) → number`
- `bfsLayers(adj list number, n number, start number) → list number`
- `isConnected(adj list number, n number) → bool`
- `shortestPathLen(adj list number, n number, start number, goal number) → number`
- `multiSourceBfs(adj list number, n number, sources list number) → list number`

## std/c/graphdfs

`import "std/c/graphdfs"` · `use graphdfs`

- `dfsOrder(adj list number, n number, start number) → list number`
- `dfsRecursiveMark(adj list number, n number) → list number`
- `hasCycleUndirected(adj list number, n number) → bool`
- `countComponents(adj list number, n number) → number`
- `topoSortDfs(adj list number, n number) → list number`
- `isTree(adj list number, n number) → bool`
- `dfsPathExists(adj list number, n number, start number, goal number) → bool`

## std/c/graphdijk

`import "std/c/graphdijk"` · `use graphdijk`

- `dijkstra(adj list number, n number, start number) → list number`
- `shortestWeighted(adj list number, n number, start number, goal number) → number`
- `dijkstraPath(adj list number, n number, start number, goal number) → list number`
- `minEdgeWeight(adj list number, n number) → number`
- `maxEdgeWeight(adj list number, n number) → number`
- `avgEdgeWeight(adj list number, n number) → number`
- `edgeCount(adj list number, n number) → number`

## std/c/graphtopo

`import "std/c/graphtopo"` · `use graphtopo`

- `topoSort(adj list number, n number) → list number`
- `hasCycleDirected(adj list number, n number) → bool`
- `inDegrees(adj list number, n number) → list number`
- `outDegrees(adj list number, n number) → list number`
- `sources(adj list number, n number) → list number`
- `sinks(adj list number, n number) → list number`
- `isDag(adj list number, n number) → bool`

## std/c/graphcc

`import "std/c/graphcc"` · `use graphcc`

- `connectedComponents(adj list number, n number) → list number`
- `componentCount(adj list number, n number) → number`
- `largestComponentSize(adj list number, n number) → number`
- `sameComponent(adj list number, n number, a number, b number) → bool`
- `componentSizes(adj list number, n number) → list number`
- `outDegreeSum(adj list number, n number) → list number`
- `isolateCount(adj list number, n number) → number`

## std/c/graphcycle

`import "std/c/graphcycle"` · `use graphcycle`

- `detectCycleDirected(adj list number, n number) → bool`
- `detectCycleUndirected(adj list number, n number) → bool`
- `cycleEdgeCount(adj list number, n number) → number`
- `isAcyclic(adj list number, n number) → bool`
- `selfLoopCount(adj list number, n number) → number`
- `removeSelfLoops(adj list number, n number) → list number`
- `hasParallelEdges(adj list number, n number) → bool`

## std/c/graphmst

`import "std/c/graphmst"` · `use graphmst`

- `mstWeightPrim(adj list number, n number) → number`
- `mstWeightKruskal(adj list number, n number) → number`
- `mstEdges(adj list number, n number) → number`
- `compareMstAlgos(adj list number, n number) → number`
- `forestMstWeight(adj list number, n number) → number`
- `isConnectedForMst(adj list number, n number) → bool`

## std/c/graphshort

`import "std/c/graphshort"` · `use graphshort`

- `allPairsBfs(adj list number, n number) → list number`
- `eccentricity(adj list number, n number) → list number`
- `graphDiameter(adj list number, n number) → number`
- `graphRadius(adj list number, n number) → number`
- `centerNodes(adj list number, n number) → list number`
- `peripheryNodes(adj list number, n number) → list number`

## std/c/graphbellman

`import "std/c/graphbellman"` · `use graphbellman`

- `bellmanFord(adj list number, n number, start number) → list number`
- `hasNegCycle(adj list number, n number) → bool`
- `negEdgeCount(adj list number, n number) → number`
- `relaxOnce(adj list number, n number, dist list number) → list number`
- `pathCost(adj list number, n number, path list number) → number`
- `reachableWeighted(adj list number, n number, start number) → number`

## std/c/graphfloyd

`import "std/c/graphfloyd"` · `use graphfloyd`

- `floydWarshall(adj list number, n number) → list number`
- `pairDistance(adj list number, n number, a number, b number) → number`
- `closureReachable(adj list number, n number) → list number`
- `graphDensity(adj list number, n number) → number`
- `avgShortestPath(adj list number, n number) → number`
- `transitiveClosure(adj list number, n number) → list number`

## std/c/graphprim

`import "std/c/graphprim"` · `use graphprim`

- `primMst(adj list number, n number) → number`
- `primParents(adj list number, n number) → list number`
- `primOrder(adj list number, n number) → list number`
- `mstEdgeCount(adj list number, n number) → number`
- `lightestEdge(adj list number, n number) → number`
- `heaviestMstEdge(adj list number, n number) → number`
- `isPrimConnected(adj list number, n number) → bool`

## std/c/graphkruskal

`import "std/c/graphkruskal"` · `use graphkruskal`

- `kruskalMst(adj list number, n number) → number`
- `kruskalEdges(adj list number, n number) → list number`
- `unionFindComponents(adj list number, n number) → number`
- `edgeListSize(adj list number, n number) → number`
- `kruskalForestWeight(adj list number, n number) → number`
- `maxSpanningForest(adj list number, n number) → number`
- `compareKruskalPrim(adj list number, n number) → number`

## std/c/graphbipart

`import "std/c/graphbipart"` · `use graphbipart`

- `isBipartite(adj list number, n number) → bool`
- `bipartiteColors(adj list number, n number) → list number`
- `partitionSizes(adj list number, n number) → list number`
- `crossEdgeCount(adj list number, n number) → number`
- `sameSideEdges(adj list number, n number) → number`
- `bipartiteDensity(adj list number, n number) → number`
- `hasOddCycle(adj list number, n number) → bool`

## std/c/grapheuler

`import "std/c/grapheuler"` · `use grapheuler`

- `vertexDegrees(adj list number, n number) → list number`
- `hasEulerCircuit(adj list number, n number) → bool`
- `hasEulerPath(adj list number, n number) → bool`
- `oddDegreeCount(adj list number, n number) → number`
- `totalDegree(adj list number, n number) → number`
- `eulerTrailLen(adj list number, n number) → number`
- `isEulerian(adj list number, n number) → bool`

## std/c/graphham

`import "std/c/graphham"` · `use graphham`

- `hamiltonianExists(adj list number, n number) → bool`
- `permuteCheck(adj list number, n number) → number`
- `longestPath(adj list number, n number) → number`
- `hamiltonianCycle(adj list number, n number) → bool`
- `pathCoverSize(adj list number, n number) → number`
- `tspLowerBound(adj list number, n number) → number`
- `nearestNeighbor(adj list number, n number, start number) → list number`

## std/c/graphclique

`import "std/c/graphclique"` · `use graphclique`

- `maxCliqueSize(adj list number, n number) → number`
- `cliqueNumber(adj list number, n number) → number`
- `isClique(adj list number, n number, nodes list number) → bool`
- `cliqueCover(adj list number, n number) → number`
- `triangleCount(adj list number, n number) → number`
- `clusteringCoeff(adj list number, n number) → list number`
- `density(adj list number, n number) → number`

## std/c/graphcolor

`import "std/c/graphcolor"` · `use graphcolor`

- `greedyColor(adj list number, n number) → list number`
- `chromaticNumber(adj list number, n number) → number`
- `isValidColoring(adj list number, n number, colors list number) → bool`
- `colorClasses(adj list number, n number) → list number`
- `conflictCount(adj list number, n number, colors list number) → number`
- `welshPowell(adj list number, n number) → list number`
- `sameColorNeighbors(adj list number, n number, node number) → number`

## std/c/graphflow

`import "std/c/graphflow"` · `use graphflow`

- `maxFlow(adj list number, n number, source number, sink number) → number`
- `minCutValue(adj list number, n number, source number, sink number) → number`
- `flowMatrix(adj list number, n number, source number, sink number) → list number`
- `bottleneckCapacity(adj list number, n number) → number`
- `outFlowSum(adj list number, n number, node number) → number`
- `inFlowSum(adj list number, n number, node number) → number`
- `isFlowConserved(adj list number, n number, source number, sink number) → bool`

## std/c/graphmatch

`import "std/c/graphmatch"` · `use graphmatch`

- `maxMatching(adj list number, n number) → number`
- `matchingPairs(adj list number, n number) → list number`
- `isPerfectMatching(adj list number, n number) → bool`
- `unmatchedCount(adj list number, n number) → number`
- `matchingWeight(adj list number, n number) → number`
- `vertexCoverSize(adj list number, n number) → number`
- `isMatched(adj list number, n number, node number) → bool`

## std/c/graphcent

`import "std/c/graphcent"` · `use graphcent`

- `degreeCentrality(adj list number, n number) → list number`
- `closenessCentrality(adj list number, n number) → list number`
- `betweennessApprox(adj list number, n number) → list number`
- `eigenvectorCentrality(adj list number, n number) → list number`
- `pageRank(adj list number, n number, damping number) → list number`
- `hubScore(adj list number, n number) → list number`
- `mostCentral(adj list number, n number) → number`

## std/c/statregress

`import "std/c/statregress"` · `use statregress`

- `regSum(v list number) → number`
- `regMean(v list number) → number`
- `regMin(v list number) → number`
- `regMax(v list number) → number`
- `regVar(v list number) → number`
- `regStd(v list number) → number`
- `regNorm(v list number) → list number`
- `linearRegress(x list number, y list number) → list number`

## std/c/statcorrel

`import "std/c/statcorrel"` · `use statcorrel`

- `pearson(a list number, b list number) → number`
- `covariance(a list number, b list number) → number`
- `crossCorr(a list number, b list number, lag number) → number`
- `autocorr1(v list number) → number`
- `partialCorr(a list number, b list number, c list number) → number`
- `corrMatrix2(a list number, b list number) → list number`
- `rankCorr(a list number, b list number) → number`

## std/c/statquartile

`import "std/c/statquartile"` · `use statquartile`

- `q1(v list number) → number`
- `q2(v list number) → number`
- `q3(v list number) → number`
- `iqr(v list number) → number`
- `quartiles(v list number) → list number`
- `fiveNum(v list number) → list number`
- `outlierFence(v list number) → list number`

## std/c/stathistogram

`import "std/c/stathistogram"` · `use stathistogram`

- `histogram(v list number, bins number) → list number`
- `binEdges(v list number, bins number) → list number`
- `freqDensity(v list number, bins number) → list number`
- `cumFreq(v list number, bins number) → list number`
- `modeBin(v list number, bins number) → number`
- `binWidth(v list number, bins number) → number`

## std/c/statanova

`import "std/c/statanova"` · `use statanova`

- `groupMeans(groups list number, labels list number) → list number`
- `grandMean(v list number) → number`
- `betweenSS(groups list number, labels list number) → number`
- `withinSS(groups list number, labels list number) → number`
- `fStatistic(groups list number, labels list number) → number`
- `etaSquared(groups list number, labels list number) → number`

## std/c/statttest

`import "std/c/statttest"` · `use statttest`

- `tStatistic(a list number, b list number) → number`
- `pooledVariance(a list number, b list number) → number`
- `cohenD(a list number, b list number) → number`
- `meanDiff(a list number, b list number) → number`
- `welchT(a list number, b list number) → number`
- `effectSize(a list number, b list number) → number`

## std/c/statchi2

`import "std/c/statchi2"` · `use statchi2`

- `chi2Stat(observed list number, expected list number) → number`
- `cramersV(chi2 number, n number, k number) → number`
- `expectedUniform(total number, bins number) → list number`
- `goodnessOfFit(observed list number, expected list number) → number`
- `residuals(observed list number, expected list number) → list number`
- `df(bins number) → number`

## std/c/statnormcdf

`import "std/c/statnormcdf"` · `use statnormcdf`

- `normPdf(x number, mu number, sigma number) → number`
- `normCdfApprox(x number, mu number, sigma number) → number`
- `zFromP(p number) → number`
- `standardize(x number, mu number, sigma number) → number`
- `logLikelihood(data list number, mu number, sigma number) → number`
- `bivariatePdf(x number, y number, rho number) → number`

## std/c/statzscore

`import "std/c/statzscore"` · `use statzscore`

- `zScores(v list number) → list number`
- `zScore(v list number, val number) → number`
- `isOutlierZ(v list number, val number, threshold number) → bool`
- `standardize(v list number) → list number`
- `destandardize(z list number, mean number, stddev number) → list number`
- `zMean(v list number) → number`

## std/c/statcovar

`import "std/c/statcovar"` · `use statcovar`

- `covSum(v list number) → number`
- `covMean(v list number) → number`
- `covMin(v list number) → number`
- `covMax(v list number) → number`
- `covVar(v list number) → number`
- `covStd(v list number) → number`
- `covNorm(v list number) → list number`
- `covariance(a list number, b list number) → number`

## std/c/statrmse

`import "std/c/statrmse"` · `use statrmse`

- `rmse(actual list number, predicted list number) → number`
- `mse(actual list number, predicted list number) → number`
- `mae(actual list number, predicted list number) → number`
- `nrmse(actual list number, predicted list number) → number`
- `smape(actual list number, predicted list number) → number`
- `r2Score(actual list number, predicted list number) → number`

## std/c/statmape

`import "std/c/statmape"` · `use statmape`

- `mape(actual list number, predicted list number) → number`
- `wape(actual list number, predicted list number) → number`
- `smape(actual list number, predicted list number) → number`
- `bias(actual list number, predicted list number) → number`
- `trackingSignal(actual list number, predicted list number) → number`
- `forecastError(actual list number, predicted list number) → list number`

## std/c/statmedian

`import "std/c/statmedian"` · `use statmedian`

- `median(v list number) → number`
- `medAbsDev(v list number) → number`
- `trimmedMean(v list number, pct number) → number`
- `movingMedian(v list number, win number) → list number`
- `weightedMedian(v list number, w list number) → number`
- `medianDiff(a list number, b list number) → number`

## std/c/statmode

`import "std/c/statmode"` · `use statmode`

- `mode(v list number) → number`
- `modeCount(v list number) → number`
- `multimodal(v list number) → bool`
- `uniqueCount(v list number) → number`
- `entropy(v list number) → number`
- `giniSimpson(v list number) → number`

## std/c/statskew

`import "std/c/statskew"` · `use statskew`

- `skewness(v list number) → number`
- `kurtosisExcess(v list number) → number`
- `moment3(v list number) → number`
- `moment4(v list number) → number`
- `jarqueBera(v list number) → number`
- `isSymmetric(v list number) → bool`

## std/c/statkurt

`import "std/c/statkurt"` · `use statkurt`

- `kurtosis(v list number) → number`
- `excessKurtosis(v list number) → number`
- `isLeptokurtic(v list number) → bool`
- `isPlatykurtic(v list number) → bool`
- `tailRatio(v list number) → number`
- `peakedness(v list number) → number`

## std/c/statbootstrap

`import "std/c/statbootstrap"` · `use statbootstrap`

- `bootstrapMean(v list number, samples number) → number`
- `bootstrapSE(v list number, samples number) → number`
- `resample(v list number, size number) → list number`
- `bootstrapCI(v list number, samples number) → list number`
- `jackknife(v list number) → list number`
- `biasCorrected(v list number, stat number) → number`

## std/c/statoutlier

`import "std/c/statoutlier"` · `use statoutlier`

- `iqrOutliers(v list number) → list number`
- `zOutliers(v list number, threshold number) → list number`
- `outlierCount(v list number) → number`
- `winsorize(v list number, pct number) → list number`
- `modifiedZ(v list number) → list number`
- `isOutlier(v list number, val number) → bool`

## std/c/statpercentile

`import "std/c/statpercentile"` · `use statpercentile`

- `percentile(v list number, p number) → number`
- `percentiles(v list number) → list number`
- `rankPct(v list number, val number) → number`
- `decile(v list number, d number) → number`
- `quantile(v list number, q number) → number`
- `p90(v list number) → number`
- `p99(v list number) → number`

## std/c/statbayes

`import "std/c/statbayes"` · `use statbayes`

- `bayesUpdate(prior number, likelihood number, evidence number) → number`
- `posteriorOdds(priorOdds number, likelihoodRatio number) → number`
- `priorFromOdds(odds number) → number`
- `oddsFromPrior(prior number) → number`
- `bayesFactor(likelihoodH1 number, likelihoodH0 number) → number`
- `credibleInterval(samples list number) → list number`
- `expectedLoss(losses list number, probs list number) → number`

## std/c/mlkmeans

`import "std/c/mlkmeans"` · `use mlkmeans`

- `kmeans(points list number, k number, dims number) → list number`
- `assignClusters(points list number, centroids list number, dims number) → list number`
- `inertia(points list number, centroids list number, dims number) → number`
- `clusterSizes(labels list number, k number) → list number`
- `silhouetteSample(points list number, labels list number, idx number, dims number) → number`
- `elbowK(points list number, maxK number, dims number) → number`

## std/c/mllinear

`import "std/c/mllinear"` · `use mllinear`

- `dot(a list number, b list number) → number`
- `predict(weights list number, features list number, bias number) → number`
- `mse(weights list number, X list number, y list number, dims number) → number`
- `gradientStep(weights list number, X list number, y list number, lr number, dims number) → list number`
- `trainEpochs(weights list number, X list number, y list number, lr number, epochs number, dims number) → list number`
- `sigmoid(x number) → number`

## std/c/mlnaivebayes

`import "std/c/mlnaivebayes"` · `use mlnaivebayes`

- `classPrior(labels list number, cls number) → number`
- `featureMean(features list number, labels list number, cls number, feat number) → number`
- `featureVar(features list number, labels list number, cls number) → number`
- `gaussianLikelihood(x number, mu number, sigma number) → number`
- `predictClass(features list number, trainX list number, trainY list number, numClasses number) → number`
- `logPosterior(features list number, trainX list number, trainY list number, cls number) → number`

## std/c/mltfidf

`import "std/c/mltfidf"` · `use mltfidf`

- `tfidSum(v list number) → number`
- `tfidMean(v list number) → number`
- `tfidMin(v list number) → number`
- `tfidMax(v list number) → number`
- `tfidVar(v list number) → number`
- `tfidStd(v list number) → number`
- `tfidNorm(v list number) → list number`

## std/c/mlcosine

`import "std/c/mlcosine"` · `use mlcosine`

- `cosineSim(a list number, b list number) → number`
- `cosineDist(a list number, b list number) → number`
- `normalize(v list number) → list number`
- `angularDist(a list number, b list number) → number`
- `batchCosine(query list number, matrix list number, dims number) → list number`
- `mostSimilar(query list number, matrix list number, dims number) → number`

## std/c/mlsvm

`import "std/c/mlsvm"` · `use mlsvm`

- `svmSum(v list number) → number`
- `svmMean(v list number) → number`
- `svmMin(v list number) → number`
- `svmMax(v list number) → number`
- `svmVar(v list number) → number`
- `svmStd(v list number) → number`
- `svmNorm(v list number) → list number`

## std/c/mlpca

`import "std/c/mlpca"` · `use mlpca`

- `pcaSum(v list number) → number`
- `pcaMean(v list number) → number`
- `pcaMin(v list number) → number`
- `pcaMax(v list number) → number`
- `pcaVar(v list number) → number`
- `pcaStd(v list number) → number`
- `pcaNorm(v list number) → list number`

## std/c/mlentropy

`import "std/c/mlentropy"` · `use mlentropy`

- `entrSum(v list number) → number`
- `entrMean(v list number) → number`
- `entrMin(v list number) → number`
- `entrMax(v list number) → number`
- `entrVar(v list number) → number`
- `entrStd(v list number) → number`
- `entrNorm(v list number) → list number`

## std/c/mlkldiv

`import "std/c/mlkldiv"` · `use mlkldiv`

- `kldiSum(v list number) → number`
- `kldiMean(v list number) → number`
- `kldiMin(v list number) → number`
- `kldiMax(v list number) → number`
- `kldiVar(v list number) → number`
- `kldiStd(v list number) → number`
- `kldiNorm(v list number) → list number`

## std/c/mlgradient

`import "std/c/mlgradient"` · `use mlgradient`

- `gradSum(v list number) → number`
- `gradMean(v list number) → number`
- `gradMin(v list number) → number`
- `gradMax(v list number) → number`
- `gradVar(v list number) → number`
- `gradStd(v list number) → number`
- `gradNorm(v list number) → list number`

## std/c/mlsoftmax

`import "std/c/mlsoftmax"` · `use mlsoftmax`

- `softmax(logits list number) → list number`
- `crossEntropy(probs list number, target number) → number`
- `argmax(v list number) → number`
- `oneHot(idx number, size number) → list number`
- `logSoftmax(logits list number) → list number`
- `entropy(probs list number) → number`

## std/c/mlperceptron

`import "std/c/mlperceptron"` · `use mlperceptron`

- `predict(weights list number, features list number, bias number) → number`
- `trainStep(weights list number, bias number, features list number, label number, lr number) → list number`
- `accuracy(weights list number, bias number, X list number, y list number, dims number) → number`
- `hingeLoss(weights list number, features list number, label number, bias number) → number`
- `initWeights(size number) → list number`
- `trainEpoch(weights list number, bias number, X list number, y list number, lr number, dims number) → list number`

## std/c/mlcrossval

`import "std/c/mlcrossval"` · `use mlcrossval`

- `crosSum(v list number) → number`
- `crosMean(v list number) → number`
- `crosMin(v list number) → number`
- `crosMax(v list number) → number`
- `crosVar(v list number) → number`
- `crosStd(v list number) → number`
- `crosNorm(v list number) → list number`

## std/c/mlfeature

`import "std/c/mlfeature"` · `use mlfeature`

- `featSum(v list number) → number`
- `featMean(v list number) → number`
- `featMin(v list number) → number`
- `featMax(v list number) → number`
- `featVar(v list number) → number`
- `featStd(v list number) → number`
- `featNorm(v list number) → list number`

## std/c/mlnormalize

`import "std/c/mlnormalize"` · `use mlnormalize`

- `normSum(v list number) → number`
- `normMean(v list number) → number`
- `normMin(v list number) → number`
- `normMax(v list number) → number`
- `normVar(v list number) → number`
- `normStd(v list number) → number`
- `normNorm(v list number) → list number`

## std/c/mldistance

`import "std/c/mldistance"` · `use mldistance`

- `distSum(v list number) → number`
- `distMean(v list number) → number`
- `distMin(v list number) → number`
- `distMax(v list number) → number`
- `distVar(v list number) → number`
- `distStd(v list number) → number`
- `distNorm(v list number) → list number`

## std/c/mlcluster

`import "std/c/mlcluster"` · `use mlcluster`

- `clusSum(v list number) → number`
- `clusMean(v list number) → number`
- `clusMin(v list number) → number`
- `clusMax(v list number) → number`
- `clusVar(v list number) → number`
- `clusStd(v list number) → number`
- `clusNorm(v list number) → list number`

## std/c/mlnearest

`import "std/c/mlnearest"` · `use mlnearest`

- `nearSum(v list number) → number`
- `nearMean(v list number) → number`
- `nearMin(v list number) → number`
- `nearMax(v list number) → number`
- `nearVar(v list number) → number`
- `nearStd(v list number) → number`
- `nearNorm(v list number) → list number`

## std/c/mldecision

`import "std/c/mldecision"` · `use mldecision`

- `deciSum(v list number) → number`
- `deciMean(v list number) → number`
- `deciMin(v list number) → number`
- `deciMax(v list number) → number`
- `deciVar(v list number) → number`
- `deciStd(v list number) → number`
- `deciNorm(v list number) → list number`

## std/c/mlensemble

`import "std/c/mlensemble"` · `use mlensemble`

- `enseSum(v list number) → number`
- `enseMean(v list number) → number`
- `enseMin(v list number) → number`
- `enseMax(v list number) → number`
- `enseVar(v list number) → number`
- `enseStd(v list number) → number`
- `enseNorm(v list number) → list number`

## std/c/cryptsha256

`import "std/c/cryptsha256"` · `use cryptsha256`

- `sha2Len(s text) → number`
- `sha2Upper(s text) → text`
- `sha2Lower(s text) → text`
- `sha2Trim(s text) → text`
- `sha2Split(s text, delim text) → list text`
- `sha2Join(parts list text, delim text) → text`
- `sha2Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptsha1

`import "std/c/cryptsha1"` · `use cryptsha1`

- `sha1Len(s text) → number`
- `sha1Upper(s text) → text`
- `sha1Lower(s text) → text`
- `sha1Trim(s text) → text`
- `sha1Split(s text, delim text) → list text`
- `sha1Join(parts list text, delim text) → text`
- `sha1Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptmd5

`import "std/c/cryptmd5"` · `use cryptmd5`

- `md5Len(s text) → number`
- `md5Upper(s text) → text`
- `md5Lower(s text) → text`
- `md5Trim(s text) → text`
- `md5Split(s text, delim text) → list text`
- `md5Join(parts list text, delim text) → text`
- `md5Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/crypthmac

`import "std/c/crypthmac"` · `use crypthmac`

- `hmacLen(s text) → number`
- `hmacUpper(s text) → text`
- `hmacLower(s text) → text`
- `hmacTrim(s text) → text`
- `hmacSplit(s text, delim text) → list text`
- `hmacJoin(parts list text, delim text) → text`
- `hmacReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptxor

`import "std/c/cryptxor"` · `use cryptxor`

- `xorBytes(a text, b text) → text`
- `xorHex(hex text, key text) → text`
- `repeatKey(data text, key text) → text`
- `xorList(a list number, b list number) → list number`
- `parity(s text) → number`
- `rollingXor(data list number, key number) → list number`
- `selfXor(s text) → text`

## std/c/cryptcaesar

`import "std/c/cryptcaesar"` · `use cryptcaesar`

- `encrypt(s text, shift number) → text`
- `decrypt(s text, shift number) → text`
- `bruteForce(s text) → list text`
- `countAlpha(s text) → number`
- `rotAll(s text) → list text`
- `isCaesar(plain text, cipher text) → bool`

## std/c/cryptvigenere

`import "std/c/cryptvigenere"` · `use cryptvigenere`

- `vigeLen(s text) → number`
- `vigeUpper(s text) → text`
- `vigeLower(s text) → text`
- `vigeTrim(s text) → text`
- `vigeSplit(s text, delim text) → list text`
- `vigeJoin(parts list text, delim text) → text`
- `vigeReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptbase64

`import "std/c/cryptbase64"` · `use cryptbase64`

- `encode(s text) → text`
- `decode(s text) → text`
- `isValid(s text) → bool`
- `paddedLen(s text) → number`
- `roundTrip(s text) → bool`
- `urlSafe(s text) → text`

## std/c/cryptrot13

`import "std/c/cryptrot13"` · `use cryptrot13`

- `rot1Len(s text) → number`
- `rot1Upper(s text) → text`
- `rot1Lower(s text) → text`
- `rot1Trim(s text) → text`
- `rot1Split(s text, delim text) → list text`
- `rot1Join(parts list text, delim text) → text`
- `rot1Replace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptaeslite

`import "std/c/cryptaeslite"` · `use cryptaeslite`

- `aeslLen(s text) → number`
- `aeslUpper(s text) → text`
- `aeslLower(s text) → text`
- `aeslTrim(s text) → text`
- `aeslSplit(s text, delim text) → list text`
- `aeslJoin(parts list text, delim text) → text`
- `aeslReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptpbkdf

`import "std/c/cryptpbkdf"` · `use cryptpbkdf`

- `pbkdLen(s text) → number`
- `pbkdUpper(s text) → text`
- `pbkdLower(s text) → text`
- `pbkdTrim(s text) → text`
- `pbkdSplit(s text, delim text) → list text`
- `pbkdJoin(parts list text, delim text) → text`
- `pbkdReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptscrypt

`import "std/c/cryptscrypt"` · `use cryptscrypt`

- `scryLen(s text) → number`
- `scryUpper(s text) → text`
- `scryLower(s text) → text`
- `scryTrim(s text) → text`
- `scrySplit(s text, delim text) → list text`
- `scryJoin(parts list text, delim text) → text`
- `scryReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptnonce

`import "std/c/cryptnonce"` · `use cryptnonce`

- `noncLen(s text) → number`
- `noncUpper(s text) → text`
- `noncLower(s text) → text`
- `noncTrim(s text) → text`
- `noncSplit(s text, delim text) → list text`
- `noncJoin(parts list text, delim text) → text`
- `noncReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/cryptcrc32

`import "std/c/cryptcrc32"` · `use cryptcrc32`

- `crc32(s text) → number`
- `crc32List(data list number) → list number`
- `verify(s text, expected number) → bool`
- `update(crc number, byte number) → number`
- `finalize(crc number) → number`
- `chunkCrc(s text, chunkSize number) → list number`

## std/c/cryptparity

`import "std/c/cryptparity"` · `use cryptparity`

- `pariLen(s text) → number`
- `pariUpper(s text) → text`
- `pariLower(s text) → text`
- `pariTrim(s text) → text`
- `pariSplit(s text, delim text) → list text`
- `pariJoin(parts list text, delim text) → text`
- `pariReplace(s text, from text, to text) → text`
- `hash32(s text) → number`

## std/c/comprle

`import "std/c/comprle"` · `use comprle`

- `rleEncode(data list number) → list number`
- `rleDecode(encoded list number) → list number`
- `rleRatio(data list number) → number`
- `runLength(data list number) → number`
- `compress(data list number) → list number`
- `decompress(encoded list number) → list number`
- `isCompressible(data list number) → bool`

## std/c/compdelta

`import "std/c/compdelta"` · `use compdelta`

- `deltaEncode(data list number) → list number`
- `deltaDecode(encoded list number) → list number`
- `deltaSum(data list number) → number`
- `secondOrder(data list number) → list number`
- `roundTrip(data list number) → bool`
- `maxDelta(data list number) → number`

## std/c/compresshuff

`import "std/c/compresshuff"` · `use compresshuff`

- `resshuffEncode(data list number) → list number`
- `resshuffDecode(encoded list number) → list number`
- `resshuffRatio(data list number) → number`
- `resshuffSize(data list number) → number`
- `resshuffCompressed(data list number) → number`
- `resshuffRoundTrip(data list number) → bool`

## std/c/complz77

`import "std/c/complz77"` · `use complz77`

- `lz77Encode(data list number) → list number`
- `lz77Decode(encoded list number) → list number`
- `lz77Ratio(data list number) → number`
- `lz77Size(data list number) → number`
- `lz77Compressed(data list number) → number`
- `lz77RoundTrip(data list number) → bool`

## std/c/complzw

`import "std/c/complzw"` · `use complzw`

- `lzwEncode(data list number) → list number`
- `lzwDecode(encoded list number) → list number`
- `lzwRatio(data list number) → number`
- `lzwSize(data list number) → number`
- `lzwCompressed(data list number) → number`
- `lzwRoundTrip(data list number) → bool`

## std/c/comprunlen

`import "std/c/comprunlen"` · `use comprunlen`

- `runlenEncode(data list number) → list number`
- `runlenDecode(encoded list number) → list number`
- `runlenRatio(data list number) → number`
- `runlenSize(data list number) → number`
- `runlenCompressed(data list number) → number`
- `runlenRoundTrip(data list number) → bool`

## std/c/compbitpack

`import "std/c/compbitpack"` · `use compbitpack`

- `bitpackEncode(data list number) → list number`
- `bitpackDecode(encoded list number) → list number`
- `bitpackRatio(data list number) → number`
- `bitpackSize(data list number) → number`
- `bitpackCompressed(data list number) → number`
- `bitpackRoundTrip(data list number) → bool`

## std/c/compvarint

`import "std/c/compvarint"` · `use compvarint`

- `varintEncode(data list number) → list number`
- `varintDecode(encoded list number) → list number`
- `varintRatio(data list number) → number`
- `varintSize(data list number) → number`
- `varintCompressed(data list number) → number`
- `varintRoundTrip(data list number) → bool`

## std/c/compdict

`import "std/c/compdict"` · `use compdict`

- `dictEncode(data list number) → list number`
- `dictDecode(encoded list number) → list number`
- `dictRatio(data list number) → number`
- `dictSize(data list number) → number`
- `dictCompressed(data list number) → number`
- `dictRoundTrip(data list number) → bool`

## std/c/compframe

`import "std/c/compframe"` · `use compframe`

- `frameEncode(data list number) → list number`
- `frameDecode(encoded list number) → list number`
- `frameRatio(data list number) → number`
- `frameSize(data list number) → number`
- `frameCompressed(data list number) → number`
- `frameRoundTrip(data list number) → bool`

## std/c/parsejsonadv

`import "std/c/parsejsonadv"` · `use parsejsonadv`

- `jsonLen(s text) → number`
- `jsonUpper(s text) → text`
- `jsonLower(s text) → text`
- `jsonTrim(s text) → text`
- `jsonSplit(s text, delim text) → list text`
- `jsonJoin(parts list text, delim text) → text`
- `jsonReplace(s text, from text, to text) → text`

## std/c/parsexml

`import "std/c/parsexml"` · `use parsexml`

- `xmlLen(s text) → number`
- `xmlUpper(s text) → text`
- `xmlLower(s text) → text`
- `xmlTrim(s text) → text`
- `xmlSplit(s text, delim text) → list text`
- `xmlJoin(parts list text, delim text) → text`
- `xmlReplace(s text, from text, to text) → text`

## std/c/parseini

`import "std/c/parseini"` · `use parseini`

- `iniLen(s text) → number`
- `iniUpper(s text) → text`
- `iniLower(s text) → text`
- `iniTrim(s text) → text`
- `iniSplit(s text, delim text) → list text`
- `iniJoin(parts list text, delim text) → text`
- `iniReplace(s text, from text, to text) → text`

## std/c/parsetoml

`import "std/c/parsetoml"` · `use parsetoml`

- `tomlLen(s text) → number`
- `tomlUpper(s text) → text`
- `tomlLower(s text) → text`
- `tomlTrim(s text) → text`
- `tomlSplit(s text, delim text) → list text`
- `tomlJoin(parts list text, delim text) → text`
- `tomlReplace(s text, from text, to text) → text`

## std/c/parsepath

`import "std/c/parsepath"` · `use parsepath`

- `pathLen(s text) → number`
- `pathUpper(s text) → text`
- `pathLower(s text) → text`
- `pathTrim(s text) → text`
- `pathSplit(s text, delim text) → list text`
- `pathJoin(parts list text, delim text) → text`
- `pathReplace(s text, from text, to text) → text`

## std/c/parseyaml

`import "std/c/parseyaml"` · `use parseyaml`

- `yamlLen(s text) → number`
- `yamlUpper(s text) → text`
- `yamlLower(s text) → text`
- `yamlTrim(s text) → text`
- `yamlSplit(s text, delim text) → list text`
- `yamlJoin(parts list text, delim text) → text`
- `yamlReplace(s text, from text, to text) → text`

## std/c/parsecsvadv

`import "std/c/parsecsvadv"` · `use parsecsvadv`

- `csvLen(s text) → number`
- `csvUpper(s text) → text`
- `csvLower(s text) → text`
- `csvTrim(s text) → text`
- `csvSplit(s text, delim text) → list text`
- `csvJoin(parts list text, delim text) → text`
- `csvReplace(s text, from text, to text) → text`
- `parseRow(line text, delim text) → list text`

## std/c/parsehtml

`import "std/c/parsehtml"` · `use parsehtml`

- `htmlLen(s text) → number`
- `htmlUpper(s text) → text`
- `htmlLower(s text) → text`
- `htmlTrim(s text) → text`
- `htmlSplit(s text, delim text) → list text`
- `htmlJoin(parts list text, delim text) → text`
- `htmlReplace(s text, from text, to text) → text`

## std/c/parselog

`import "std/c/parselog"` · `use parselog`

- `logLen(s text) → number`
- `logUpper(s text) → text`
- `logLower(s text) → text`
- `logTrim(s text) → text`
- `logSplit(s text, delim text) → list text`
- `logJoin(parts list text, delim text) → text`
- `logReplace(s text, from text, to text) → text`

## std/c/parseuri

`import "std/c/parseuri"` · `use parseuri`

- `scheme(uri text) → text`
- `host(uri text) → text`
- `path(uri text) → text`
- `query(uri text) → text`
- `fragment(uri text) → text`
- `port(uri text) → number`
- `isValid(uri text) → bool`

## std/c/parsemime

`import "std/c/parsemime"` · `use parsemime`

- `mimeLen(s text) → number`
- `mimeUpper(s text) → text`
- `mimeLower(s text) → text`
- `mimeTrim(s text) → text`
- `mimeSplit(s text, delim text) → list text`
- `mimeJoin(parts list text, delim text) → text`
- `mimeReplace(s text, from text, to text) → text`

## std/c/parsehex

`import "std/c/parsehex"` · `use parsehex`

- `decode(hex text) → list number`
- `encode(bytes list number) → text`
- `nibbleCount(hex text) → number`
- `byteCount(hex text) → number`
- `isHex(s text) → bool`
- `roundTrip(bytes list number) → bool`

## std/c/parsebinary

`import "std/c/parsebinary"` · `use parsebinary`

- `binaLen(s text) → number`
- `binaUpper(s text) → text`
- `binaLower(s text) → text`
- `binaTrim(s text) → text`
- `binaSplit(s text, delim text) → list text`
- `binaJoin(parts list text, delim text) → text`
- `binaReplace(s text, from text, to text) → text`

## std/c/parsetemplate

`import "std/c/parsetemplate"` · `use parsetemplate`

- `tempLen(s text) → number`
- `tempUpper(s text) → text`
- `tempLower(s text) → text`
- `tempTrim(s text) → text`
- `tempSplit(s text, delim text) → list text`
- `tempJoin(parts list text, delim text) → text`
- `tempReplace(s text, from text, to text) → text`

## std/c/parseexpr

`import "std/c/parseexpr"` · `use parseexpr`

- `exprLen(s text) → number`
- `exprUpper(s text) → text`
- `exprLower(s text) → text`
- `exprTrim(s text) → text`
- `exprSplit(s text, delim text) → list text`
- `exprJoin(parts list text, delim text) → text`
- `exprReplace(s text, from text, to text) → text`

## std/c/csvfilter

`import "std/c/csvfilter"` · `use csvfilter`

- `filtSum(v list number) → number`
- `filtMean(v list number) → number`
- `filtMin(v list number) → number`
- `filtMax(v list number) → number`
- `filtVar(v list number) → number`
- `filtStd(v list number) → number`
- `filtNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvgroup

`import "std/c/csvgroup"` · `use csvgroup`

- `groupSum(values list number, keys list number) → list number`
- `groupCount(keys list number) → list number`
- `groupMean(values list number, keys list number) → list number`
- `uniqueKeys(keys list number) → list number`
- `groupMax(values list number, keys list number) → list number`
- `numGroups(keys list number) → number`

## std/c/csvaggregate

`import "std/c/csvaggregate"` · `use csvaggregate`

- `aggrSum(v list number) → number`
- `aggrMean(v list number) → number`
- `aggrMin(v list number) → number`
- `aggrMax(v list number) → number`
- `aggrVar(v list number) → number`
- `aggrStd(v list number) → number`
- `aggrNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvjoin

`import "std/c/csvjoin"` · `use csvjoin`

- `joinSum(v list number) → number`
- `joinMean(v list number) → number`
- `joinMin(v list number) → number`
- `joinMax(v list number) → number`
- `joinVar(v list number) → number`
- `joinStd(v list number) → number`
- `joinNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvpivot

`import "std/c/csvpivot"` · `use csvpivot`

- `pivoSum(v list number) → number`
- `pivoMean(v list number) → number`
- `pivoMin(v list number) → number`
- `pivoMax(v list number) → number`
- `pivoVar(v list number) → number`
- `pivoStd(v list number) → number`
- `pivoNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvsort

`import "std/c/csvsort"` · `use csvsort`

- `sortAsc(col list number) → list number`
- `sortDesc(col list number) → list number`
- `argsort(col list number) → list number`
- `rank(col list number) → list number`
- `topK(col list number, k number) → list number`
- `bottomK(col list number, k number) → list number`

## std/c/csvselect

`import "std/c/csvselect"` · `use csvselect`

- `seleSum(v list number) → number`
- `seleMean(v list number) → number`
- `seleMin(v list number) → number`
- `seleMax(v list number) → number`
- `seleVar(v list number) → number`
- `seleStd(v list number) → number`
- `seleNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvdistinct

`import "std/c/csvdistinct"` · `use csvdistinct`

- `distSum(v list number) → number`
- `distMean(v list number) → number`
- `distMin(v list number) → number`
- `distMax(v list number) → number`
- `distVar(v list number) → number`
- `distStd(v list number) → number`
- `distNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvlimit

`import "std/c/csvlimit"` · `use csvlimit`

- `limiSum(v list number) → number`
- `limiMean(v list number) → number`
- `limiMin(v list number) → number`
- `limiMax(v list number) → number`
- `limiVar(v list number) → number`
- `limiStd(v list number) → number`
- `limiNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvhaving

`import "std/c/csvhaving"` · `use csvhaving`

- `haviSum(v list number) → number`
- `haviMean(v list number) → number`
- `haviMin(v list number) → number`
- `haviMax(v list number) → number`
- `haviVar(v list number) → number`
- `haviStd(v list number) → number`
- `haviNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvunion

`import "std/c/csvunion"` · `use csvunion`

- `unioSum(v list number) → number`
- `unioMean(v list number) → number`
- `unioMin(v list number) → number`
- `unioMax(v list number) → number`
- `unioVar(v list number) → number`
- `unioStd(v list number) → number`
- `unioNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvwindow

`import "std/c/csvwindow"` · `use csvwindow`

- `windSum(v list number) → number`
- `windMean(v list number) → number`
- `windMin(v list number) → number`
- `windMax(v list number) → number`
- `windVar(v list number) → number`
- `windStd(v list number) → number`
- `windNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvnormalize

`import "std/c/csvnormalize"` · `use csvnormalize`

- `normSum(v list number) → number`
- `normMean(v list number) → number`
- `normMin(v list number) → number`
- `normMax(v list number) → number`
- `normVar(v list number) → number`
- `normStd(v list number) → number`
- `normNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvrollup

`import "std/c/csvrollup"` · `use csvrollup`

- `rollSum(v list number) → number`
- `rollMean(v list number) → number`
- `rollMin(v list number) → number`
- `rollMax(v list number) → number`
- `rollVar(v list number) → number`
- `rollStd(v list number) → number`
- `rollNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/csvsample

`import "std/c/csvsample"` · `use csvsample`

- `sampSum(v list number) → number`
- `sampMean(v list number) → number`
- `sampMin(v list number) → number`
- `sampMax(v list number) → number`
- `sampVar(v list number) → number`
- `sampStd(v list number) → number`
- `sampNorm(v list number) → list number`
- `filterGt(col list number, threshold number) → list number`

## std/c/simmonte

`import "std/c/simmonte"` · `use simmonte`

- `estimatePi(samples number, seed number) → number`
- `integrate(samples number, seed number, a number, b number) → number`
- `randomNormal(n number, seed number) → list number`
- `confidence95(samples list number) → list number`
- `bootstrapMean(data list number, samples number, seed number) → number`
- `varianceReduction(samples number, seed number) → number`

## std/c/simmarkov

`import "std/c/simmarkov"` · `use simmarkov`

- `steadyState(trans list number, states number) → list number`
- `simulate(trans list number, states number, steps number, seed number) → list number`
- `transitionProb(trans list number, states number, from number, to number) → number`
- `expectedSteps(trans list number, states number, target number) → number`
- `isStochastic(trans list number, states number) → bool`
- `mixingTime(trans list number, states number) → number`

## std/c/simrandomwalk

`import "std/c/simrandomwalk"` · `use simrandomwalk`

- `randSum(v list number) → number`
- `randMean(v list number) → number`
- `randMin(v list number) → number`
- `randMax(v list number) → number`
- `randVar(v list number) → number`
- `randStd(v list number) → number`
- `randNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simbrownian

`import "std/c/simbrownian"` · `use simbrownian`

- `browSum(v list number) → number`
- `browMean(v list number) → number`
- `browMin(v list number) → number`
- `browMax(v list number) → number`
- `browVar(v list number) → number`
- `browStd(v list number) → number`
- `browNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simpoisson

`import "std/c/simpoisson"` · `use simpoisson`

- `poisSum(v list number) → number`
- `poisMean(v list number) → number`
- `poisMin(v list number) → number`
- `poisMax(v list number) → number`
- `poisVar(v list number) → number`
- `poisStd(v list number) → number`
- `poisNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simqueue

`import "std/c/simqueue"` · `use simqueue`

- `queuSum(v list number) → number`
- `queuMean(v list number) → number`
- `queuMin(v list number) → number`
- `queuMax(v list number) → number`
- `queuVar(v list number) → number`
- `queuStd(v list number) → number`
- `queuNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/siminventory

`import "std/c/siminventory"` · `use siminventory`

- `inveSum(v list number) → number`
- `inveMean(v list number) → number`
- `inveMin(v list number) → number`
- `inveMax(v list number) → number`
- `inveVar(v list number) → number`
- `inveStd(v list number) → number`
- `inveNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simdiscrete

`import "std/c/simdiscrete"` · `use simdiscrete`

- `discSum(v list number) → number`
- `discMean(v list number) → number`
- `discMin(v list number) → number`
- `discMax(v list number) → number`
- `discVar(v list number) → number`
- `discStd(v list number) → number`
- `discNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simlorenz

`import "std/c/simlorenz"` · `use simlorenz`

- `loreSum(v list number) → number`
- `loreMean(v list number) → number`
- `loreMin(v list number) → number`
- `loreMax(v list number) → number`
- `loreVar(v list number) → number`
- `loreStd(v list number) → number`
- `loreNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/simbirth

`import "std/c/simbirth"` · `use simbirth`

- `birtSum(v list number) → number`
- `birtMean(v list number) → number`
- `birtMin(v list number) → number`
- `birtMax(v list number) → number`
- `birtVar(v list number) → number`
- `birtStd(v list number) → number`
- `birtNorm(v list number) → list number`
- `simulate(steps number, seed number) → list number`

## std/c/finoption

`import "std/c/finoption"` · `use finoption`

- `blackScholes(spot number, strike number, rate number, vol number, time number) → number`
- `putPrice(spot number, strike number, rate number, vol number, time number) → number`
- `intrinsic(spot number, strike number) → number`
- `timeValue(spot number, strike number, rate number, vol number, time number) → number`
- `delta(spot number, strike number, rate number, vol number, time number) → number`
- `gamma(spot number, strike number, rate number, vol number, time number) → number`
- `vega(spot number, strike number, rate number, vol number, time number) → number`

## std/c/finbond

`import "std/c/finbond"` · `use finbond`

- `pv(face number, rate number, years number, coupon number) → number`
- `ytm(price number, face number, coupon number, years number) → number`
- `duration(face number, rate number, years number, coupon number) → number`
- `convexity(face number, rate number, years number, coupon number) → number`
- `couponYield(coupon number, price number) → number`
- `accruedInterest(coupon number, days number) → number`

## std/c/finportfolio

`import "std/c/finportfolio"` · `use finportfolio`

- `portSum(v list number) → number`
- `portMean(v list number) → number`
- `portMin(v list number) → number`
- `portMax(v list number) → number`
- `portVar(v list number) → number`
- `portStd(v list number) → number`
- `portNorm(v list number) → list number`

## std/c/finblack

`import "std/c/finblack"` · `use finblack`

- `blacSum(v list number) → number`
- `blacMean(v list number) → number`
- `blacMin(v list number) → number`
- `blacMax(v list number) → number`
- `blacVar(v list number) → number`
- `blacStd(v list number) → number`
- `blacNorm(v list number) → list number`

## std/c/fingreeks

`import "std/c/fingreeks"` · `use fingreeks`

- `greeSum(v list number) → number`
- `greeMean(v list number) → number`
- `greeMin(v list number) → number`
- `greeMax(v list number) → number`
- `greeVar(v list number) → number`
- `greeStd(v list number) → number`
- `greeNorm(v list number) → list number`

## std/c/finyield

`import "std/c/finyield"` · `use finyield`

- `yielSum(v list number) → number`
- `yielMean(v list number) → number`
- `yielMin(v list number) → number`
- `yielMax(v list number) → number`
- `yielVar(v list number) → number`
- `yielStd(v list number) → number`
- `yielNorm(v list number) → list number`

## std/c/finsharpe

`import "std/c/finsharpe"` · `use finsharpe`

- `sharpe(returns list number, rf number) → number`
- `sortino(returns list number, rf number) → number`
- `maxDrawdown(prices list number) → number`
- `calmar(returns list number, prices list number) → number`
- `volatility(returns list number) → number`
- `annualizedReturn(returns list number, periods number) → number`

## std/c/finvar

`import "std/c/finvar"` · `use finvar`

- `varSum(v list number) → number`
- `varMean(v list number) → number`
- `varMin(v list number) → number`
- `varMax(v list number) → number`
- `varVar(v list number) → number`
- `varStd(v list number) → number`
- `varNorm(v list number) → list number`

## std/c/finforex

`import "std/c/finforex"` · `use finforex`

- `foreSum(v list number) → number`
- `foreMean(v list number) → number`
- `foreMin(v list number) → number`
- `foreMax(v list number) → number`
- `foreVar(v list number) → number`
- `foreStd(v list number) → number`
- `foreNorm(v list number) → list number`

## std/c/finamort

`import "std/c/finamort"` · `use finamort`

- `amorSum(v list number) → number`
- `amorMean(v list number) → number`
- `amorMin(v list number) → number`
- `amorMax(v list number) → number`
- `amorVar(v list number) → number`
- `amorStd(v list number) → number`
- `amorNorm(v list number) → list number`

## std/c/finfutures

`import "std/c/finfutures"` · `use finfutures`

- `futuSum(v list number) → number`
- `futuMean(v list number) → number`
- `futuMin(v list number) → number`
- `futuMax(v list number) → number`
- `futuVar(v list number) → number`
- `futuStd(v list number) → number`
- `futuNorm(v list number) → list number`

## std/c/finswap

`import "std/c/finswap"` · `use finswap`

- `swapSum(v list number) → number`
- `swapMean(v list number) → number`
- `swapMin(v list number) → number`
- `swapMax(v list number) → number`
- `swapVar(v list number) → number`
- `swapStd(v list number) → number`
- `swapNorm(v list number) → list number`

## std/c/finrisk

`import "std/c/finrisk"` · `use finrisk`

- `riskSum(v list number) → number`
- `riskMean(v list number) → number`
- `riskMin(v list number) → number`
- `riskMax(v list number) → number`
- `riskVar(v list number) → number`
- `riskStd(v list number) → number`
- `riskNorm(v list number) → list number`

## std/c/finhedge

`import "std/c/finhedge"` · `use finhedge`

- `hedgSum(v list number) → number`
- `hedgMean(v list number) → number`
- `hedgMin(v list number) → number`
- `hedgMax(v list number) → number`
- `hedgVar(v list number) → number`
- `hedgStd(v list number) → number`
- `hedgNorm(v list number) → list number`

## std/c/findividend

`import "std/c/findividend"` · `use findividend`

- `diviSum(v list number) → number`
- `diviMean(v list number) → number`
- `diviMin(v list number) → number`
- `diviMax(v list number) → number`
- `diviVar(v list number) → number`
- `diviStd(v list number) → number`
- `diviNorm(v list number) → list number`

## std/c/sigconv

`import "std/c/sigconv"` · `use sigconv`

- `convolve(a list number, b list number) → list number`
- `crossCorr(a list number, b list number) → list number`
- `movingAvg(v list number, win number) → list number`
- `deconvSimple(signal list number, kernel list number) → list number`
- `energy(v list number) → number`
- `normalize(v list number) → list number`

## std/c/sigfft

`import "std/c/sigfft"` · `use sigfft`

- `dft(signal list number) → list number`
- `magnitude(signal list number) → list number`
- `powerSpectrum(signal list number) → list number`
- `dominantFreq(signal list number) → number`
- `inverseDft(spectrum list number, n number) → list number`
- `bandEnergy(signal list number, lo number, hi number) → number`

## std/c/sigpoly

`import "std/c/sigpoly"` · `use sigpoly`

- `polySum(v list number) → number`
- `polyMean(v list number) → number`
- `polyMin(v list number) → number`
- `polyMax(v list number) → number`
- `polyVar(v list number) → number`
- `polyStd(v list number) → number`
- `polyNorm(v list number) → list number`

## std/c/sigeigen

`import "std/c/sigeigen"` · `use sigeigen`

- `eigeSum(v list number) → number`
- `eigeMean(v list number) → number`
- `eigeMin(v list number) → number`
- `eigeMax(v list number) → number`
- `eigeVar(v list number) → number`
- `eigeStd(v list number) → number`
- `eigeNorm(v list number) → list number`

## std/c/sigmatrix

`import "std/c/sigmatrix"` · `use sigmatrix`

- `matrSum(v list number) → number`
- `matrMean(v list number) → number`
- `matrMin(v list number) → number`
- `matrMax(v list number) → number`
- `matrVar(v list number) → number`
- `matrStd(v list number) → number`
- `matrNorm(v list number) → list number`

## std/c/sigintegral

`import "std/c/sigintegral"` · `use sigintegral`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/sigderivative

`import "std/c/sigderivative"` · `use sigderivative`

- `deriSum(v list number) → number`
- `deriMean(v list number) → number`
- `deriMin(v list number) → number`
- `deriMax(v list number) → number`
- `deriVar(v list number) → number`
- `deriStd(v list number) → number`
- `deriNorm(v list number) → list number`

## std/c/sigfilter

`import "std/c/sigfilter"` · `use sigfilter`

- `lowPass(v list number, alpha number) → list number`
- `highPass(v list number, alpha number) → list number`
- `medianFilter(v list number, win number) → list number`
- `savgol(v list number, win number) → list number`
- `bandpass(v list number, lo number, hi number) → list number`
- `snr(signal list number, noise list number) → number`

## std/c/sigwavelet

`import "std/c/sigwavelet"` · `use sigwavelet`

- `waveSum(v list number) → number`
- `waveMean(v list number) → number`
- `waveMin(v list number) → number`
- `waveMax(v list number) → number`
- `waveVar(v list number) → number`
- `waveStd(v list number) → number`
- `waveNorm(v list number) → list number`

## std/c/sigresample

`import "std/c/sigresample"` · `use sigresample`

- `resaSum(v list number) → number`
- `resaMean(v list number) → number`
- `resaMin(v list number) → number`
- `resaMax(v list number) → number`
- `resaVar(v list number) → number`
- `resaStd(v list number) → number`
- `resaNorm(v list number) → list number`

## std/c/siginterpolate

`import "std/c/siginterpolate"` · `use siginterpolate`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/sigspline

`import "std/c/sigspline"` · `use sigspline`

- `spliSum(v list number) → number`
- `spliMean(v list number) → number`
- `spliMin(v list number) → number`
- `spliMax(v list number) → number`
- `spliVar(v list number) → number`
- `spliStd(v list number) → number`
- `spliNorm(v list number) → list number`

## std/c/sigcorrel

`import "std/c/sigcorrel"` · `use sigcorrel`

- `corrSum(v list number) → number`
- `corrMean(v list number) → number`
- `corrMin(v list number) → number`
- `corrMax(v list number) → number`
- `corrVar(v list number) → number`
- `corrStd(v list number) → number`
- `corrNorm(v list number) → list number`

## std/c/sigautocorr

`import "std/c/sigautocorr"` · `use sigautocorr`

- `autoSum(v list number) → number`
- `autoMean(v list number) → number`
- `autoMin(v list number) → number`
- `autoMax(v list number) → number`
- `autoVar(v list number) → number`
- `autoStd(v list number) → number`
- `autoNorm(v list number) → list number`

## std/c/sigpower

`import "std/c/sigpower"` · `use sigpower`

- `poweSum(v list number) → number`
- `poweMean(v list number) → number`
- `poweMin(v list number) → number`
- `poweMax(v list number) → number`
- `poweVar(v list number) → number`
- `poweStd(v list number) → number`
- `poweNorm(v list number) → list number`

## std/c/nlpstem

`import "std/c/nlpstem"` · `use nlpstem`

- `stemLen(s text) → number`
- `stemUpper(s text) → text`
- `stemLower(s text) → text`
- `stemTrim(s text) → text`
- `stemSplit(s text, delim text) → list text`
- `stemJoin(parts list text, delim text) → text`
- `stemReplace(s text, from text, to text) → text`

## std/c/nlplevenshtein

`import "std/c/nlplevenshtein"` · `use nlplevenshtein`

- `distance(a text, b text) → number`
- `similarity(a text, b text) → number`
- `ratio(a text, b text) → number`
- `isClose(a text, b text, maxDist number) → bool`
- `normalizedDist(a text, b text) → number`
- `longestCommon(a text, b text) → number`

## std/c/nlpjaccard

`import "std/c/nlpjaccard"` · `use nlpjaccard`

- `similarity(a text, b text) → number`
- `tokenJaccard(a text, b text) → number`
- `distance(a text, b text) → number`
- `ngramJaccard(a text, b text, n number) → number`
- `overlap(a text, b text) → number`
- `dice(a text, b text) → number`

## std/c/nlpedit

`import "std/c/nlpedit"` · `use nlpedit`

- `editLen(s text) → number`
- `editUpper(s text) → text`
- `editLower(s text) → text`
- `editTrim(s text) → text`
- `editSplit(s text, delim text) → list text`
- `editJoin(parts list text, delim text) → text`
- `editReplace(s text, from text, to text) → text`

## std/c/nlptoken

`import "std/c/nlptoken"` · `use nlptoken`

- `tokeLen(s text) → number`
- `tokeUpper(s text) → text`
- `tokeLower(s text) → text`
- `tokeTrim(s text) → text`
- `tokeSplit(s text, delim text) → list text`
- `tokeJoin(parts list text, delim text) → text`
- `tokeReplace(s text, from text, to text) → text`

## std/c/nlpngram

`import "std/c/nlpngram"` · `use nlpngram`

- `ngraLen(s text) → number`
- `ngraUpper(s text) → text`
- `ngraLower(s text) → text`
- `ngraTrim(s text) → text`
- `ngraSplit(s text, delim text) → list text`
- `ngraJoin(parts list text, delim text) → text`
- `ngraReplace(s text, from text, to text) → text`

## std/c/nlpbow

`import "std/c/nlpbow"` · `use nlpbow`

- `bowLen(s text) → number`
- `bowUpper(s text) → text`
- `bowLower(s text) → text`
- `bowTrim(s text) → text`
- `bowSplit(s text, delim text) → list text`
- `bowJoin(parts list text, delim text) → text`
- `bowReplace(s text, from text, to text) → text`

## std/c/nlpstop

`import "std/c/nlpstop"` · `use nlpstop`

- `stopLen(s text) → number`
- `stopUpper(s text) → text`
- `stopLower(s text) → text`
- `stopTrim(s text) → text`
- `stopSplit(s text, delim text) → list text`
- `stopJoin(parts list text, delim text) → text`
- `stopReplace(s text, from text, to text) → text`

## std/c/nlpphrase

`import "std/c/nlpphrase"` · `use nlpphrase`

- `phraLen(s text) → number`
- `phraUpper(s text) → text`
- `phraLower(s text) → text`
- `phraTrim(s text) → text`
- `phraSplit(s text, delim text) → list text`
- `phraJoin(parts list text, delim text) → text`
- `phraReplace(s text, from text, to text) → text`

## std/c/nlpsentiment

`import "std/c/nlpsentiment"` · `use nlpsentiment`

- `sentLen(s text) → number`
- `sentUpper(s text) → text`
- `sentLower(s text) → text`
- `sentTrim(s text) → text`
- `sentSplit(s text, delim text) → list text`
- `sentJoin(parts list text, delim text) → text`
- `sentReplace(s text, from text, to text) → text`

## std/c/nlpkeyword

`import "std/c/nlpkeyword"` · `use nlpkeyword`

- `keywLen(s text) → number`
- `keywUpper(s text) → text`
- `keywLower(s text) → text`
- `keywTrim(s text) → text`
- `keywSplit(s text, delim text) → list text`
- `keywJoin(parts list text, delim text) → text`
- `keywReplace(s text, from text, to text) → text`

## std/c/nlptfidf

`import "std/c/nlptfidf"` · `use nlptfidf`

- `tf(doc text, term text) → number`
- `idf(term text, corpus list text) → number`
- `tfidf(doc text, term text, corpus list text) → number`
- `docVector(doc text, terms list text, corpus list text) → list number`
- `cosineSim(a list number, b list number) → number`
- `rankTerms(doc text, corpus list text) → list text`

## std/c/nlpoverlap

`import "std/c/nlpoverlap"` · `use nlpoverlap`

- `overLen(s text) → number`
- `overUpper(s text) → text`
- `overLower(s text) → text`
- `overTrim(s text) → text`
- `overSplit(s text, delim text) → list text`
- `overJoin(parts list text, delim text) → text`
- `overReplace(s text, from text, to text) → text`

## std/c/nlpsimhash

`import "std/c/nlpsimhash"` · `use nlpsimhash`

- `simhLen(s text) → number`
- `simhUpper(s text) → text`
- `simhLower(s text) → text`
- `simhTrim(s text) → text`
- `simhSplit(s text, delim text) → list text`
- `simhJoin(parts list text, delim text) → text`
- `simhReplace(s text, from text, to text) → text`

## std/c/nlpcompress

`import "std/c/nlpcompress"` · `use nlpcompress`

- `compLen(s text) → number`
- `compUpper(s text) → text`
- `compLower(s text) → text`
- `compTrim(s text) → text`
- `compSplit(s text, delim text) → list text`
- `compJoin(parts list text, delim text) → text`
- `compReplace(s text, from text, to text) → text`

## std/c/tsma

`import "std/c/tsma"` · `use tsma`

- `sma(v list number, win number) → list number`
- `wma(v list number, win number) → list number`
- `dema(v list number, win number) → list number`
- `crossover(v list number, fast number, slow number) → list number`
- `signal(v list number, fast number, slow number) → number`
- `trend(v list number, win number) → number`

## std/c/tsema

`import "std/c/tsema"` · `use tsema`

- `ema(v list number, alpha number) → list number`
- `emaSpan(v list number, span number) → list number`
- `macd(v list number) → list number`
- `macdSignal(v list number) → list number`
- `histogram(v list number) → list number`
- `lastEma(v list number, alpha number) → number`

## std/c/tsautocorr

`import "std/c/tsautocorr"` · `use tsautocorr`

- `autoSum(v list number) → number`
- `autoMean(v list number) → number`
- `autoMin(v list number) → number`
- `autoMax(v list number) → number`
- `autoVar(v list number) → number`
- `autoStd(v list number) → number`
- `autoNorm(v list number) → list number`

## std/c/tsseason

`import "std/c/tsseason"` · `use tsseason`

- `seasSum(v list number) → number`
- `seasMean(v list number) → number`
- `seasMin(v list number) → number`
- `seasMax(v list number) → number`
- `seasVar(v list number) → number`
- `seasStd(v list number) → number`
- `seasNorm(v list number) → list number`

## std/c/tsdecompose

`import "std/c/tsdecompose"` · `use tsdecompose`

- `decoSum(v list number) → number`
- `decoMean(v list number) → number`
- `decoMin(v list number) → number`
- `decoMax(v list number) → number`
- `decoVar(v list number) → number`
- `decoStd(v list number) → number`
- `decoNorm(v list number) → list number`

## std/c/tsforecast

`import "std/c/tsforecast"` · `use tsforecast`

- `foreSum(v list number) → number`
- `foreMean(v list number) → number`
- `foreMin(v list number) → number`
- `foreMax(v list number) → number`
- `foreVar(v list number) → number`
- `foreStd(v list number) → number`
- `foreNorm(v list number) → list number`

## std/c/tsanomaly

`import "std/c/tsanomaly"` · `use tsanomaly`

- `anomSum(v list number) → number`
- `anomMean(v list number) → number`
- `anomMin(v list number) → number`
- `anomMax(v list number) → number`
- `anomVar(v list number) → number`
- `anomStd(v list number) → number`
- `anomNorm(v list number) → list number`

## std/c/tsrolling

`import "std/c/tsrolling"` · `use tsrolling`

- `rollSum(v list number) → number`
- `rollMean(v list number) → number`
- `rollMin(v list number) → number`
- `rollMax(v list number) → number`
- `rollVar(v list number) → number`
- `rollStd(v list number) → number`
- `rollNorm(v list number) → list number`

## std/c/tscumulative

`import "std/c/tscumulative"` · `use tscumulative`

- `cumuSum(v list number) → number`
- `cumuMean(v list number) → number`
- `cumuMin(v list number) → number`
- `cumuMax(v list number) → number`
- `cumuVar(v list number) → number`
- `cumuStd(v list number) → number`
- `cumuNorm(v list number) → list number`

## std/c/tsdiff

`import "std/c/tsdiff"` · `use tsdiff`

- `diff(v list number, order number) → list number`
- `pctChange(v list number) → list number`
- `logReturn(v list number) → list number`
- `cumReturn(v list number) → list number`
- `seasonalDiff(v list number, period number) → list number`
- `integrate(v list number, start number) → list number`

## std/c/geomhull

`import "std/c/geomhull"` · `use geomhull`

- `hullSum(v list number) → number`
- `hullMean(v list number) → number`
- `hullMin(v list number) → number`
- `hullMax(v list number) → number`
- `hullVar(v list number) → number`
- `hullStd(v list number) → number`
- `hullNorm(v list number) → list number`

## std/c/geompolygon

`import "std/c/geompolygon"` · `use geompolygon`

- `polySum(v list number) → number`
- `polyMean(v list number) → number`
- `polyMin(v list number) → number`
- `polyMax(v list number) → number`
- `polyVar(v list number) → number`
- `polyStd(v list number) → number`
- `polyNorm(v list number) → list number`

## std/c/geomline

`import "std/c/geomline"` · `use geomline`

- `lineSum(v list number) → number`
- `lineMean(v list number) → number`
- `lineMin(v list number) → number`
- `lineMax(v list number) → number`
- `lineVar(v list number) → number`
- `lineStd(v list number) → number`
- `lineNorm(v list number) → list number`

## std/c/geomcircle

`import "std/c/geomcircle"` · `use geomcircle`

- `euclidean2d(x1 number, y1 number, x2 number, y2 number) → number`
- `area(r number) → number`
- `circumference(r number) → number`
- `contains(cx number, cy number, r number, px number, py number) → bool`
- `pointAt(cx number, cy number, r number, angle number) → list number`
- `intersectArea(r1 number, r2 number, d number) → number`

## std/c/geombezier

`import "std/c/geombezier"` · `use geombezier`

- `beziSum(v list number) → number`
- `beziMean(v list number) → number`
- `beziMin(v list number) → number`
- `beziMax(v list number) → number`
- `beziVar(v list number) → number`
- `beziStd(v list number) → number`
- `beziNorm(v list number) → list number`

## std/c/geomclip

`import "std/c/geomclip"` · `use geomclip`

- `clipSum(v list number) → number`
- `clipMean(v list number) → number`
- `clipMin(v list number) → number`
- `clipMax(v list number) → number`
- `clipVar(v list number) → number`
- `clipStd(v list number) → number`
- `clipNorm(v list number) → list number`

## std/c/geomrotate

`import "std/c/geomrotate"` · `use geomrotate`

- `rotaSum(v list number) → number`
- `rotaMean(v list number) → number`
- `rotaMin(v list number) → number`
- `rotaMax(v list number) → number`
- `rotaVar(v list number) → number`
- `rotaStd(v list number) → number`
- `rotaNorm(v list number) → list number`

## std/c/geomscale

`import "std/c/geomscale"` · `use geomscale`

- `scalSum(v list number) → number`
- `scalMean(v list number) → number`
- `scalMin(v list number) → number`
- `scalMax(v list number) → number`
- `scalVar(v list number) → number`
- `scalStd(v list number) → number`
- `scalNorm(v list number) → list number`

## std/c/geomintersect

`import "std/c/geomintersect"` · `use geomintersect`

- `inteSum(v list number) → number`
- `inteMean(v list number) → number`
- `inteMin(v list number) → number`
- `inteMax(v list number) → number`
- `inteVar(v list number) → number`
- `inteStd(v list number) → number`
- `inteNorm(v list number) → list number`

## std/c/geomdistance

`import "std/c/geomdistance"` · `use geomdistance`

- `euclidean2d(x1 number, y1 number, x2 number, y2 number) → number`
- `manhattan2d(x1 number, y1 number, x2 number, y2 number) → number`
- `chebyshev2d(x1 number, y1 number, x2 number, y2 number) → number`
- `pointToLine(px number, py number, x1 number, y1 number, x2 number, y2 number) → number`
- `pairwiseDist(points list number) → list number`
- `centroid2d(points list number) → list number`
- `bbox2d(points list number) → list number`

## std/c/netip

`import "std/c/netip"` · `use netip`

- `parseOctets(ip text) → list number`
- `toInt(ip text) → number`
- `fromInt(n number) → text`
- `isPrivate(ip text) → bool`
- `isValid(ip text) → bool`
- `sameSubnet(a text, b text, mask number) → bool`
- `broadcast(ip text, mask number) → text`

## std/c/netsubnet

`import "std/c/netsubnet"` · `use netsubnet`

- `subnLen(s text) → number`
- `subnUpper(s text) → text`
- `subnLower(s text) → text`
- `subnTrim(s text) → text`
- `subnSplit(s text, delim text) → list text`
- `subnJoin(parts list text, delim text) → text`
- `subnReplace(s text, from text, to text) → text`

## std/c/netcidr

`import "std/c/netcidr"` · `use netcidr`

- `prefixLen(cidr text) → number`
- `hostCount(cidr text) → number`
- `maskFromPrefix(prefix number) → number`
- `ipToInt(ip text) → number`
- `networkInt(cidr text) → number`
- `containsIp(cidr text, ip text) → bool`
- `broadcastInt(cidr text) → number`

## std/c/netpacket

`import "std/c/netpacket"` · `use netpacket`

- `packLen(s text) → number`
- `packUpper(s text) → text`
- `packLower(s text) → text`
- `packTrim(s text) → text`
- `packSplit(s text, delim text) → list text`
- `packJoin(parts list text, delim text) → text`
- `packReplace(s text, from text, to text) → text`

## std/c/netmac

`import "std/c/netmac"` · `use netmac`

- `macLen(s text) → number`
- `macUpper(s text) → text`
- `macLower(s text) → text`
- `macTrim(s text) → text`
- `macSplit(s text, delim text) → list text`
- `macJoin(parts list text, delim text) → text`
- `macReplace(s text, from text, to text) → text`

## std/c/netdns

`import "std/c/netdns"` · `use netdns`

- `dnsLen(s text) → number`
- `dnsUpper(s text) → text`
- `dnsLower(s text) → text`
- `dnsTrim(s text) → text`
- `dnsSplit(s text, delim text) → list text`
- `dnsJoin(parts list text, delim text) → text`
- `dnsReplace(s text, from text, to text) → text`

## std/c/netport

`import "std/c/netport"` · `use netport`

- `portLen(s text) → number`
- `portUpper(s text) → text`
- `portLower(s text) → text`
- `portTrim(s text) → text`
- `portSplit(s text, delim text) → list text`
- `portJoin(parts list text, delim text) → text`
- `portReplace(s text, from text, to text) → text`

## std/c/netroute

`import "std/c/netroute"` · `use netroute`

- `routLen(s text) → number`
- `routUpper(s text) → text`
- `routLower(s text) → text`
- `routTrim(s text) → text`
- `routSplit(s text, delim text) → list text`
- `routJoin(parts list text, delim text) → text`
- `routReplace(s text, from text, to text) → text`

## std/c/netping

`import "std/c/netping"` · `use netping`

- `pingLen(s text) → number`
- `pingUpper(s text) → text`
- `pingLower(s text) → text`
- `pingTrim(s text) → text`
- `pingSplit(s text, delim text) → list text`
- `pingJoin(parts list text, delim text) → text`
- `pingReplace(s text, from text, to text) → text`

## std/c/netchecksum

`import "std/c/netchecksum"` · `use netchecksum`

- `ipChecksum(data list number) → number`
- `onesComplement(n number) → number`
- `fold32(sum number) → number`
- `verify(data list number, expected number) → bool`
- `pseudoHeader(src list number, dst list number, proto number, len number) → list number`
- `tcpChecksum(header list number, payload list number) → number`

## std/c/gameminimax

`import "std/c/gameminimax"` · `use gameminimax`

- `minimax(board list number, depth number, maximizing bool) → number`
- `bestMove(board list number, depth number) → number`
- `evaluate(board list number) → number`
- `isTerminal(board list number) → bool`
- `negamax(board list number, depth number, color number) → number`
- `depthReached(depth number) → number`
- `scoreDiff(board list number) → number`

## std/c/gamealphabeta

`import "std/c/gamealphabeta"` · `use gamealphabeta`

- `alphabeta(board list number, depth number, alpha number, beta number, maximizing bool) → number`
- `bestMove(board list number, depth number) → number`
- `pruneCount(board list number, depth number) → number`
- `evaluate(board list number) → number`
- `search(board list number, depth number) → number`
- `isWinning(board list number) → bool`
- `windowSearch(board list number, depth number, window number) → number`

## std/c/gameastar

`import "std/c/gameastar"` · `use gameastar`

- `heuristic(ax number, ay number, bx number, by number) → number`
- `astar(grid list number, width number, start number, goal number) → list number`
- `pathCost(grid list number, width number, start number, goal number) → number`
- `reconstruct(cameFrom list number, current number) → list number`
- `manhattan(ax number, ay number, bx number, by number) → number`
- `octile(ax number, ay number, bx number, by number) → number`
- `openSetSize(grid list number) → number`

## std/c/gamedijkstra

`import "std/c/gamedijkstra"` · `use gamedijkstra`

- `gridDijkstra(grid list number, width number, start number) → list number`
- `shortestCost(grid list number, width number, start number, goal number) → number`
- `reachableCells(grid list number, width number, start number) → number`
- `multiGoal(grid list number, width number, start number, goals list number) → list number`
- `relaxStep(dist list number, grid list number, width number, u number) → list number`
- `maxDist(grid list number, width number, start number) → number`

## std/c/gamemcts

`import "std/c/gamemcts"` · `use gamemcts`

- `uctSelect(wins list number, visits list number, totalVisits number, explore number) → number`
- `rollout(state list number, depth number) → number`
- `simulate(state list number, sims number) → number`
- `bestAction(wins list number, visits list number) → number`
- `updateStats(wins list number, visits list number, action number, reward number) → list number`
- `treePolicy(state list number, actions list number) → number`
- `mctsValue(wins list number, visits list number) → number`

## std/c/gamepathfind

`import "std/c/gamepathfind"` · `use gamepathfind`

- `bfsPath(grid list number, width number, start number, goal number) → list number`
- `pathLen(grid list number, width number, start number, goal number) → number`
- `lineOfSight(grid list number, width number, x0 number, y0 number, x1 number, y1 number) → bool`
- `smoothPath(path list number, grid list number, width number) → list number`
- `waypoints(path list number, step number) → list number`
- `navCost(grid list number, width number, start number, goal number) → number`

## std/c/gamenavmesh

`import "std/c/gamenavmesh"` · `use gamenavmesh`

- `pointInTri(px number, py number, ax number, ay number, bx number, by number, cx number, cy number) → bool`
- `triArea(ax number, ay number, bx number, by number, cx number, cy number) → number`
- `portalMid(a list number, b list number) → list number`
- `navDistance(a list number, b list number) → number`
- `funnelCost(path list number) → number`
- `centroid(ax number, ay number, bx number, by number, cx number, cy number) → list number`
- `meshQuality(ax number, ay number, bx number, by number, cx number, cy number) → number`

## std/c/gamebehavior

`import "std/c/gamebehavior"` · `use gamebehavior`

- `evalSelector(scores list number) → number`
- `evalSequence(scores list number) → number`
- `evalParallel(scores list number) → number`
- `blackboardGet(keys list text, values list number, key text) → number`
- `blackboardSet(keys list text, values list number, key text, val number) → list number`
- `cooldownReady(last number, now number, cd number) → bool`
- `weightedPick(weights list number) → number`

## std/c/gameflood

`import "std/c/gameflood"` · `use gameflood`

- `floodFill(grid list number, width number, start number, newVal number) → list number`
- `connectedRegion(grid list number, width number, start number) → number`
- `countRegions(grid list number, width number) → number`
- `fillDist(grid list number, width number, start number) → list number`
- `reachable(grid list number, width number, start number) → number`
- `boundary(grid list number, width number, start number) → list number`

## std/c/gametree

`import "std/c/gametree"` · `use gametree`

- `branchingFactor(children list number) → number`
- `treeDepth(depths list number) → number`
- `minimaxLeaf(values list number, maxNode bool) → number`
- `expectimax(values list number, probs list number) → number`
- `alphaBetaWindow(alpha number, beta number) → list number`
- `gameTreeSize(branching number, depth number) → number`
- `plyCount(moves list number) → number`
- `bestChild(scores list number) → number`
